# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/alvari/Myfile/workspace/rosboat/serv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alvari/Myfile/workspace/rosboat/serv/build

# Include any dependencies generated for this target.
include CMakeFiles/rosserv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rosserv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rosserv.dir/flags.make

CMakeFiles/rosserv.dir/server.cpp.o: CMakeFiles/rosserv.dir/flags.make
CMakeFiles/rosserv.dir/server.cpp.o: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvari/Myfile/workspace/rosboat/serv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rosserv.dir/server.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rosserv.dir/server.cpp.o -c /home/alvari/Myfile/workspace/rosboat/serv/server.cpp

CMakeFiles/rosserv.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rosserv.dir/server.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvari/Myfile/workspace/rosboat/serv/server.cpp > CMakeFiles/rosserv.dir/server.cpp.i

CMakeFiles/rosserv.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rosserv.dir/server.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvari/Myfile/workspace/rosboat/serv/server.cpp -o CMakeFiles/rosserv.dir/server.cpp.s

CMakeFiles/rosserv.dir/common.cpp.o: CMakeFiles/rosserv.dir/flags.make
CMakeFiles/rosserv.dir/common.cpp.o: ../common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvari/Myfile/workspace/rosboat/serv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rosserv.dir/common.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rosserv.dir/common.cpp.o -c /home/alvari/Myfile/workspace/rosboat/serv/common.cpp

CMakeFiles/rosserv.dir/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rosserv.dir/common.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvari/Myfile/workspace/rosboat/serv/common.cpp > CMakeFiles/rosserv.dir/common.cpp.i

CMakeFiles/rosserv.dir/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rosserv.dir/common.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvari/Myfile/workspace/rosboat/serv/common.cpp -o CMakeFiles/rosserv.dir/common.cpp.s

# Object files for target rosserv
rosserv_OBJECTS = \
"CMakeFiles/rosserv.dir/server.cpp.o" \
"CMakeFiles/rosserv.dir/common.cpp.o"

# External object files for target rosserv
rosserv_EXTERNAL_OBJECTS =

librosserv.a: CMakeFiles/rosserv.dir/server.cpp.o
librosserv.a: CMakeFiles/rosserv.dir/common.cpp.o
librosserv.a: CMakeFiles/rosserv.dir/build.make
librosserv.a: CMakeFiles/rosserv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alvari/Myfile/workspace/rosboat/serv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library librosserv.a"
	$(CMAKE_COMMAND) -P CMakeFiles/rosserv.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rosserv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rosserv.dir/build: librosserv.a

.PHONY : CMakeFiles/rosserv.dir/build

CMakeFiles/rosserv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rosserv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rosserv.dir/clean

CMakeFiles/rosserv.dir/depend:
	cd /home/alvari/Myfile/workspace/rosboat/serv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alvari/Myfile/workspace/rosboat/serv /home/alvari/Myfile/workspace/rosboat/serv /home/alvari/Myfile/workspace/rosboat/serv/build /home/alvari/Myfile/workspace/rosboat/serv/build /home/alvari/Myfile/workspace/rosboat/serv/build/CMakeFiles/rosserv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rosserv.dir/depend

