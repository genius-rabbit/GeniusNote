# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /install/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /install/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/delta/deltaNote/deltaNote_client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/delta/deltaNote/deltaNote_client/cmake-build-debug

# Utility rule file for deltaNote_client_autogen.

# Include the progress variables for this target.
include CMakeFiles/deltaNote_client_autogen.dir/progress.make

CMakeFiles/deltaNote_client_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/delta/deltaNote/deltaNote_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target deltaNote_client"
	/install/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake -E cmake_autogen /home/delta/deltaNote/deltaNote_client/cmake-build-debug/CMakeFiles/deltaNote_client_autogen.dir/AutogenInfo.cmake Debug

deltaNote_client_autogen: CMakeFiles/deltaNote_client_autogen
deltaNote_client_autogen: CMakeFiles/deltaNote_client_autogen.dir/build.make

.PHONY : deltaNote_client_autogen

# Rule to build all files generated by this target.
CMakeFiles/deltaNote_client_autogen.dir/build: deltaNote_client_autogen

.PHONY : CMakeFiles/deltaNote_client_autogen.dir/build

CMakeFiles/deltaNote_client_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/deltaNote_client_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/deltaNote_client_autogen.dir/clean

CMakeFiles/deltaNote_client_autogen.dir/depend:
	cd /home/delta/deltaNote/deltaNote_client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/delta/deltaNote/deltaNote_client /home/delta/deltaNote/deltaNote_client /home/delta/deltaNote/deltaNote_client/cmake-build-debug /home/delta/deltaNote/deltaNote_client/cmake-build-debug /home/delta/deltaNote/deltaNote_client/cmake-build-debug/CMakeFiles/deltaNote_client_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/deltaNote_client_autogen.dir/depend

