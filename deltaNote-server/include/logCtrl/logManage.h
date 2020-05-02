//
// Created by delta on 2020/4/9.
//

#ifndef DELTANOTE_LOGMANAGE_H
#define DELTANOTE_LOGMANAGE_H

#include <string>
#include <iostream>

enum LOG_LEVEL{
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
};

enum OUTPUT {
    OUTPUT_FILE,
    OUTPUT_SCREEN
};

class LogManage {
public:
    static LogManage* instance();

    void logMessage(short level, std::string &message);

    void setOutput(OUTPUT output);
    void setLoglevel(LOG_LEVEL logLevel);
    void setLogFileName(std::string &fileName);

protected:
    LogManage();

private:
    static std::string getLevelStr(short level);
    bool isGreaterThanLevel(short level);

    // log to file
    void logMsgToFile(short level, std::string &message);

    // log to screen
    void logMsgToScreen(short level, std::string &message);

    // get log file name
    std::string getLogFilePath();

    // get two bits num
    std::string getTwoBitsNumber(int i);

private:
    static LogManage* _instance;

/**
 * LocalLogCtrl setting
 */
private:
    LOG_LEVEL outputLogLevel;
    OUTPUT outputLocation;

    std::string logFileName;
};
#endif //DELTANOTE_LOGMANAGE_H
