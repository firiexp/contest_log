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
include CMakeFiles/2000.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2000.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2000.dir/flags.make

CMakeFiles/2000.dir/volume20/2000.cpp.o: CMakeFiles/2000.dir/flags.make
CMakeFiles/2000.dir/volume20/2000.cpp.o: ../volume20/2000.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2000.dir/volume20/2000.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2000.dir/volume20/2000.cpp.o -c /mnt/d/competitive-programming-code/cpp/AOJ/volume20/2000.cpp

CMakeFiles/2000.dir/volume20/2000.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2000.dir/volume20/2000.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/competitive-programming-code/cpp/AOJ/volume20/2000.cpp > CMakeFiles/2000.dir/volume20/2000.cpp.i

CMakeFiles/2000.dir/volume20/2000.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2000.dir/volume20/2000.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/competitive-programming-code/cpp/AOJ/volume20/2000.cpp -o CMakeFiles/2000.dir/volume20/2000.cpp.s

CMakeFiles/2000.dir/volume20/2000.cpp.o.requires:

.PHONY : CMakeFiles/2000.dir/volume20/2000.cpp.o.requires

CMakeFiles/2000.dir/volume20/2000.cpp.o.provides: CMakeFiles/2000.dir/volume20/2000.cpp.o.requires
	$(MAKE) -f CMakeFiles/2000.dir/build.make CMakeFiles/2000.dir/volume20/2000.cpp.o.provides.build
.PHONY : CMakeFiles/2000.dir/volume20/2000.cpp.o.provides

CMakeFiles/2000.dir/volume20/2000.cpp.o.provides.build: CMakeFiles/2000.dir/volume20/2000.cpp.o


# Object files for target 2000
2000_OBJECTS = \
"CMakeFiles/2000.dir/volume20/2000.cpp.o"

# External object files for target 2000
2000_EXTERNAL_OBJECTS =

2000: CMakeFiles/2000.dir/volume20/2000.cpp.o
2000: CMakeFiles/2000.dir/build.make
2000: CMakeFiles/2000.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2000"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2000.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2000.dir/build: 2000

.PHONY : CMakeFiles/2000.dir/build

CMakeFiles/2000.dir/requires: CMakeFiles/2000.dir/volume20/2000.cpp.o.requires

.PHONY : CMakeFiles/2000.dir/requires

CMakeFiles/2000.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2000.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2000.dir/clean

CMakeFiles/2000.dir/depend:
	cd /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/competitive-programming-code/cpp/AOJ /mnt/d/competitive-programming-code/cpp/AOJ /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles/2000.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2000.dir/depend

