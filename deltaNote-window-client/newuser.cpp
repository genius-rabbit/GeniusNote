#include "newuser.h"
#include "ui_newuser.h"

extern char g_username[G_ARR_SIZE_USERNAME];
extern char g_passwd[G_ARR_SIZE_PASSWD];

extern char g_server[G_ARR_SIZE_SERVER];
extern int g_port;

extern bool isLogin;

extern QColor fontColor;
extern QColor iconColor;
extern int transparentPos;
extern bool cleanFlag;

newUser::newUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUser)
{
    ui->setupUi(this);
    ui->server_port->setPlaceholderText("server:port");
    string server_port = string(g_server) + ":" + to_string(g_port);
    ui->server_port->setText(QString(server_port.data()));
    ui->username->setPlaceholderText("username");
    ui->passwd->setPlaceholderText("password");
    ui->repasswd ->setPlaceholderText("rewrite password");
    ui->username->setFocus();
}

newUser::~newUser()
{
    delete ui;
}

void newUser::on_ok_clicked()
{
    QString QS_server_port = ui->server_port->text().trimmed();
    QString QS_username = ui->username->text().trimmed();
    QString QS_passwd = ui->passwd->text();
    QString QS_repasswd = ui->repasswd->text();

    if(nullptr == QS_server_port){
        ui->server_port->setFocus();
        QMessageBox::warning(this, tr("Error"), tr("server & port is null!"), QMessageBox::Yes);
    } else if (nullptr == QS_username) {
        ui->username->setFocus();
        QMessageBox::warning(this, tr("Error"), tr("username is null!"), QMessageBox::Yes);
    } else if (nullptr == QS_passwd) {
        ui->passwd->setFocus();
        QMessageBox::warning(this, tr("Error"), tr("password is null!"), QMessageBox::Yes);
    } else if (nullptr == QS_repasswd) {
        ui->repasswd->setFocus();
        QMessageBox::warning(this, tr("Error"), tr("password is null!"), QMessageBox::Yes);
    } else if (0 != QS_passwd.compare(QS_repasswd)) {
        ui->passwd->clear();
        ui->repasswd->clear();
        ui->passwd->setFocus();
        QMessageBox::warning(this, tr("Error"), tr("password is inconpable!"), QMessageBox::Yes);
    } else {
        // read data and create user
        char server_port[G_ARR_SIZE_SERVER_PORT]{};
        strcpy(server_port, QS_server_port.toUtf8().data());
        parserServerPort(server_port);

        ClientSqlite sqlite;
        sqlite.alterSetting("server", g_server);
        sqlite.alterSetting("port", to_string(g_port).data());

        // connect server
        SocketClient socketClient = SocketClient(g_server, g_port);
        if(SocketError == socketClient.getSocketOpState()){
            QMessageBox::warning(this, tr("Error"), tr("Socket connect error!"), QMessageBox::Yes);
        }

        // get username and passwd
        MSG_PACK send{};
        send.msgOp = CreateUser;
        strcpy(send.userName, QS_username.toUtf8().data());
        strcpy(send.passwd, QS_passwd.toUtf8().data());

        ret = socketClient.sendMsg(&send, sizeof(send));

        MSG_PACK recv{};
        ret = socketClient.recvMsg(&recv, sizeof(recv));

        if (recv.msgState == CreateUserSuccess) {
            isLogin = true;
            strcpy(g_username, send.userName);
            strcpy(g_passwd, send.passwd);

            sqlite.alterSetting("username", g_username);
            sqlite.alterSetting("passwd", g_passwd);

            if(cleanFlag){
                MSG_PACK synPack{};
                makeSocketPack(synPack, 1, MSG_FULL, Delete);

                if(CleanSuccess == synMsgToServer(synPack)){
                    cleanFlag = false;
                }else{
                    QMessageBox::warning(this, tr("Error"), tr("server clean data error!"), QMessageBox::Yes);
                    LOG_ERROR("clean data error")
                }
            }

            // send local change to server
            synLocalChange();

            accept();
        } else if (recv.msgState == CreateUserUserExists) {
            ui->username->clear();
            ui->username->setFocus();
            QMessageBox::warning(this, tr("Error"), tr("username is exists!"), QMessageBox::Yes);
        } else if (recv.msgState == CreateUserUndefinedError) {
            QMessageBox::warning(this, tr("Error"), tr("server undefined error!"), QMessageBox::Yes);
        } else {
            QMessageBox::warning(this, tr("Error"), tr("client undefined error!"), QMessageBox::Yes);
        }
    }
}

void newUser::on_cancel_clicked()
{
    reject();
}
