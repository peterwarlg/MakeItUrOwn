# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wangzitu/02Project/webserver_sep/webserver_ed1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/webserver_new.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/webserver_new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/webserver_new.dir/flags.make

CMakeFiles/webserver_new.dir/main.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/webserver_new.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/main.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/main.cpp

CMakeFiles/webserver_new.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/main.cpp > CMakeFiles/webserver_new.dir/main.cpp.i

CMakeFiles/webserver_new.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/main.cpp -o CMakeFiles/webserver_new.dir/main.cpp.s

CMakeFiles/webserver_new.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/main.cpp.o.requires

CMakeFiles/webserver_new.dir/main.cpp.o.provides: CMakeFiles/webserver_new.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/main.cpp.o.provides

CMakeFiles/webserver_new.dir/main.cpp.o.provides.build: CMakeFiles/webserver_new.dir/main.cpp.o


CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o: ../src/Socket/ServerSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Socket/ServerSocket.cpp

CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Socket/ServerSocket.cpp > CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.i

CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Socket/ServerSocket.cpp -o CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.s

CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o.requires

CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o.provides: CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o.provides

CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o.provides.build: CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o


CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o: ../src/Http/HttpRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpRequest.cpp

CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpRequest.cpp > CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.i

CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpRequest.cpp -o CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.s

CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o.requires

CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o.provides: CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o.provides

CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o.provides.build: CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o


CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o: ../src/Http/HttpResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpResponse.cpp

CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpResponse.cpp > CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.i

CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpResponse.cpp -o CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.s

CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o.requires

CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o.provides: CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o.provides

CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o.provides.build: CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o


CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o: ../src/Http/HttpData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpData.cpp

CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpData.cpp > CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.i

CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpData.cpp -o CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.s

CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o.requires

CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o.provides: CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o.provides

CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o.provides.build: CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o


CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o: ../src/Http/HttpParse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpParse.cpp

CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpParse.cpp > CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.i

CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Http/HttpParse.cpp -o CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.s

CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o.requires

CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o.provides: CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o.provides

CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o.provides.build: CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o


CMakeFiles/webserver_new.dir/src/Util.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/src/Util.cpp.o: ../src/Util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/webserver_new.dir/src/Util.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/src/Util.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Util.cpp

CMakeFiles/webserver_new.dir/src/Util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/src/Util.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Util.cpp > CMakeFiles/webserver_new.dir/src/Util.cpp.i

CMakeFiles/webserver_new.dir/src/Util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/src/Util.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Util.cpp -o CMakeFiles/webserver_new.dir/src/Util.cpp.s

CMakeFiles/webserver_new.dir/src/Util.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/src/Util.cpp.o.requires

CMakeFiles/webserver_new.dir/src/Util.cpp.o.provides: CMakeFiles/webserver_new.dir/src/Util.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/src/Util.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/src/Util.cpp.o.provides

CMakeFiles/webserver_new.dir/src/Util.cpp.o.provides.build: CMakeFiles/webserver_new.dir/src/Util.cpp.o


CMakeFiles/webserver_new.dir/src/Epoll.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/src/Epoll.cpp.o: ../src/Epoll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/webserver_new.dir/src/Epoll.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/src/Epoll.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Epoll.cpp

CMakeFiles/webserver_new.dir/src/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/src/Epoll.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Epoll.cpp > CMakeFiles/webserver_new.dir/src/Epoll.cpp.i

CMakeFiles/webserver_new.dir/src/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/src/Epoll.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Epoll.cpp -o CMakeFiles/webserver_new.dir/src/Epoll.cpp.s

CMakeFiles/webserver_new.dir/src/Epoll.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/src/Epoll.cpp.o.requires

CMakeFiles/webserver_new.dir/src/Epoll.cpp.o.provides: CMakeFiles/webserver_new.dir/src/Epoll.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/src/Epoll.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/src/Epoll.cpp.o.provides

CMakeFiles/webserver_new.dir/src/Epoll.cpp.o.provides.build: CMakeFiles/webserver_new.dir/src/Epoll.cpp.o


CMakeFiles/webserver_new.dir/src/Server.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/src/Server.cpp.o: ../src/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/webserver_new.dir/src/Server.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/src/Server.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Server.cpp

CMakeFiles/webserver_new.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/src/Server.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Server.cpp > CMakeFiles/webserver_new.dir/src/Server.cpp.i

CMakeFiles/webserver_new.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/src/Server.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Server.cpp -o CMakeFiles/webserver_new.dir/src/Server.cpp.s

CMakeFiles/webserver_new.dir/src/Server.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/src/Server.cpp.o.requires

CMakeFiles/webserver_new.dir/src/Server.cpp.o.provides: CMakeFiles/webserver_new.dir/src/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/src/Server.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/src/Server.cpp.o.provides

CMakeFiles/webserver_new.dir/src/Server.cpp.o.provides.build: CMakeFiles/webserver_new.dir/src/Server.cpp.o


CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o: CMakeFiles/webserver_new.dir/flags.make
CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o: ../src/Socket/ClientSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o -c /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Socket/ClientSocket.cpp

CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Socket/ClientSocket.cpp > CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.i

CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/02Project/webserver_sep/webserver_ed1/src/Socket/ClientSocket.cpp -o CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.s

CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o.requires:

.PHONY : CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o.requires

CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o.provides: CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/webserver_new.dir/build.make CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o.provides.build
.PHONY : CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o.provides

CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o.provides.build: CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o


# Object files for target webserver_new
webserver_new_OBJECTS = \
"CMakeFiles/webserver_new.dir/main.cpp.o" \
"CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o" \
"CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o" \
"CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o" \
"CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o" \
"CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o" \
"CMakeFiles/webserver_new.dir/src/Util.cpp.o" \
"CMakeFiles/webserver_new.dir/src/Epoll.cpp.o" \
"CMakeFiles/webserver_new.dir/src/Server.cpp.o" \
"CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o"

# External object files for target webserver_new
webserver_new_EXTERNAL_OBJECTS =

webserver_new: CMakeFiles/webserver_new.dir/main.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/src/Util.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/src/Epoll.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/src/Server.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o
webserver_new: CMakeFiles/webserver_new.dir/build.make
webserver_new: CMakeFiles/webserver_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable webserver_new"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/webserver_new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/webserver_new.dir/build: webserver_new

.PHONY : CMakeFiles/webserver_new.dir/build

CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/main.cpp.o.requires
CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/src/Socket/ServerSocket.cpp.o.requires
CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/src/Http/HttpRequest.cpp.o.requires
CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/src/Http/HttpResponse.cpp.o.requires
CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/src/Http/HttpData.cpp.o.requires
CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/src/Http/HttpParse.cpp.o.requires
CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/src/Util.cpp.o.requires
CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/src/Epoll.cpp.o.requires
CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/src/Server.cpp.o.requires
CMakeFiles/webserver_new.dir/requires: CMakeFiles/webserver_new.dir/src/Socket/ClientSocket.cpp.o.requires

.PHONY : CMakeFiles/webserver_new.dir/requires

CMakeFiles/webserver_new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/webserver_new.dir/cmake_clean.cmake
.PHONY : CMakeFiles/webserver_new.dir/clean

CMakeFiles/webserver_new.dir/depend:
	cd /home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wangzitu/02Project/webserver_sep/webserver_ed1 /home/wangzitu/02Project/webserver_sep/webserver_ed1 /home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug /home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug /home/wangzitu/02Project/webserver_sep/webserver_ed1/cmake-build-debug/CMakeFiles/webserver_new.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/webserver_new.dir/depend

