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
CMAKE_SOURCE_DIR = /home/alvari/Myfile/workspace/rosboat/clnt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alvari/Myfile/workspace/rosboat/clnt/build

# Include any dependencies generated for this target.
include CMakeFiles/rosclnt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rosclnt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rosclnt.dir/flags.make

CMakeFiles/rosclnt.dir/client.cpp.o: CMakeFiles/rosclnt.dir/flags.make
CMakeFiles/rosclnt.dir/client.cpp.o: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvari/Myfile/workspace/rosboat/clnt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rosclnt.dir/client.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rosclnt.dir/client.cpp.o -c /home/alvari/Myfile/workspace/rosboat/clnt/client.cpp

CMakeFiles/rosclnt.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rosclnt.dir/client.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvari/Myfile/workspace/rosboat/clnt/client.cpp > CMakeFiles/rosclnt.dir/client.cpp.i

CMakeFiles/rosclnt.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rosclnt.dir/client.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvari/Myfile/workspace/rosboat/clnt/client.cpp -o CMakeFiles/rosclnt.dir/client.cpp.s

CMakeFiles/rosclnt.dir/makeclnt4.cpp.o: CMakeFiles/rosclnt.dir/flags.make
CMakeFiles/rosclnt.dir/makeclnt4.cpp.o: ../makeclnt4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alvari/Myfile/workspace/rosboat/clnt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rosclnt.dir/makeclnt4.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rosclnt.dir/makeclnt4.cpp.o -c /home/alvari/Myfile/workspace/rosboat/clnt/makeclnt4.cpp

CMakeFiles/rosclnt.dir/makeclnt4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rosclnt.dir/makeclnt4.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alvari/Myfile/workspace/rosboat/clnt/makeclnt4.cpp > CMakeFiles/rosclnt.dir/makeclnt4.cpp.i

CMakeFiles/rosclnt.dir/makeclnt4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rosclnt.dir/makeclnt4.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alvari/Myfile/workspace/rosboat/clnt/makeclnt4.cpp -o CMakeFiles/rosclnt.dir/makeclnt4.cpp.s

# Object files for target rosclnt
rosclnt_OBJECTS = \
"CMakeFiles/rosclnt.dir/client.cpp.o" \
"CMakeFiles/rosclnt.dir/makeclnt4.cpp.o"

# External object files for target rosclnt
rosclnt_EXTERNAL_OBJECTS =

librosclnt.a: CMakeFiles/rosclnt.dir/client.cpp.o
librosclnt.a: CMakeFiles/rosclnt.dir/makeclnt4.cpp.o
librosclnt.a: CMakeFiles/rosclnt.dir/build.make
librosclnt.a: CMakeFiles/rosclnt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alvari/Myfile/workspace/rosboat/clnt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library librosclnt.a"
	$(CMAKE_COMMAND) -P CMakeFiles/rosclnt.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rosclnt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rosclnt.dir/build: librosclnt.a

.PHONY : CMakeFiles/rosclnt.dir/build

CMakeFiles/rosclnt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rosclnt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rosclnt.dir/clean

CMakeFiles/rosclnt.dir/depend:
	cd /home/alvari/Myfile/workspace/rosboat/clnt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alvari/Myfile/workspace/rosboat/clnt /home/alvari/Myfile/workspace/rosboat/clnt /home/alvari/Myfile/workspace/rosboat/clnt/build /home/alvari/Myfile/workspace/rosboat/clnt/build /home/alvari/Myfile/workspace/rosboat/clnt/build/CMakeFiles/rosclnt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rosclnt.dir/depend

