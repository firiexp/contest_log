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
CMAKE_SOURCE_DIR = /mnt/d/competitive-programming-code/cpp/AOJ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cccddd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cccddd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cccddd.dir/flags.make

CMakeFiles/cccddd.dir/cccddd.cpp.o: CMakeFiles/cccddd.dir/flags.make
CMakeFiles/cccddd.dir/cccddd.cpp.o: ../cccddd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cccddd.dir/cccddd.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cccddd.dir/cccddd.cpp.o -c /mnt/d/competitive-programming-code/cpp/AOJ/cccddd.cpp

CMakeFiles/cccddd.dir/cccddd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cccddd.dir/cccddd.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/competitive-programming-code/cpp/AOJ/cccddd.cpp > CMakeFiles/cccddd.dir/cccddd.cpp.i

CMakeFiles/cccddd.dir/cccddd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cccddd.dir/cccddd.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/competitive-programming-code/cpp/AOJ/cccddd.cpp -o CMakeFiles/cccddd.dir/cccddd.cpp.s

CMakeFiles/cccddd.dir/cccddd.cpp.o.requires:

.PHONY : CMakeFiles/cccddd.dir/cccddd.cpp.o.requires

CMakeFiles/cccddd.dir/cccddd.cpp.o.provides: CMakeFiles/cccddd.dir/cccddd.cpp.o.requires
	$(MAKE) -f CMakeFiles/cccddd.dir/build.make CMakeFiles/cccddd.dir/cccddd.cpp.o.provides.build
.PHONY : CMakeFiles/cccddd.dir/cccddd.cpp.o.provides

CMakeFiles/cccddd.dir/cccddd.cpp.o.provides.build: CMakeFiles/cccddd.dir/cccddd.cpp.o


# Object files for target cccddd
cccddd_OBJECTS = \
"CMakeFiles/cccddd.dir/cccddd.cpp.o"

# External object files for target cccddd
cccddd_EXTERNAL_OBJECTS =

cccddd: CMakeFiles/cccddd.dir/cccddd.cpp.o
cccddd: CMakeFiles/cccddd.dir/build.make
cccddd: CMakeFiles/cccddd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cccddd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cccddd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cccddd.dir/build: cccddd

.PHONY : CMakeFiles/cccddd.dir/build

CMakeFiles/cccddd.dir/requires: CMakeFiles/cccddd.dir/cccddd.cpp.o.requires

.PHONY : CMakeFiles/cccddd.dir/requires

CMakeFiles/cccddd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cccddd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cccddd.dir/clean

CMakeFiles/cccddd.dir/depend:
	cd /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/competitive-programming-code/cpp/AOJ /mnt/d/competitive-programming-code/cpp/AOJ /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles/cccddd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cccddd.dir/depend
