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
include CMakeFiles/1618.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1618.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1618.dir/flags.make

CMakeFiles/1618.dir/1618.cpp.o: CMakeFiles/1618.dir/flags.make
CMakeFiles/1618.dir/1618.cpp.o: ../1618.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1618.dir/1618.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1618.dir/1618.cpp.o -c /mnt/d/competitive-programming-code/cpp/AOJ/1618.cpp

CMakeFiles/1618.dir/1618.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1618.dir/1618.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/competitive-programming-code/cpp/AOJ/1618.cpp > CMakeFiles/1618.dir/1618.cpp.i

CMakeFiles/1618.dir/1618.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1618.dir/1618.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/competitive-programming-code/cpp/AOJ/1618.cpp -o CMakeFiles/1618.dir/1618.cpp.s

CMakeFiles/1618.dir/1618.cpp.o.requires:

.PHONY : CMakeFiles/1618.dir/1618.cpp.o.requires

CMakeFiles/1618.dir/1618.cpp.o.provides: CMakeFiles/1618.dir/1618.cpp.o.requires
	$(MAKE) -f CMakeFiles/1618.dir/build.make CMakeFiles/1618.dir/1618.cpp.o.provides.build
.PHONY : CMakeFiles/1618.dir/1618.cpp.o.provides

CMakeFiles/1618.dir/1618.cpp.o.provides.build: CMakeFiles/1618.dir/1618.cpp.o


# Object files for target 1618
1618_OBJECTS = \
"CMakeFiles/1618.dir/1618.cpp.o"

# External object files for target 1618
1618_EXTERNAL_OBJECTS =

1618: CMakeFiles/1618.dir/1618.cpp.o
1618: CMakeFiles/1618.dir/build.make
1618: CMakeFiles/1618.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1618"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1618.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1618.dir/build: 1618

.PHONY : CMakeFiles/1618.dir/build

CMakeFiles/1618.dir/requires: CMakeFiles/1618.dir/1618.cpp.o.requires

.PHONY : CMakeFiles/1618.dir/requires

CMakeFiles/1618.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1618.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1618.dir/clean

CMakeFiles/1618.dir/depend:
	cd /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/competitive-programming-code/cpp/AOJ /mnt/d/competitive-programming-code/cpp/AOJ /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles/1618.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1618.dir/depend

