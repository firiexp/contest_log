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
include CMakeFiles/aaabbb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aaabbb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aaabbb.dir/flags.make

CMakeFiles/aaabbb.dir/aaabbb.cpp.o: CMakeFiles/aaabbb.dir/flags.make
CMakeFiles/aaabbb.dir/aaabbb.cpp.o: ../aaabbb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aaabbb.dir/aaabbb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aaabbb.dir/aaabbb.cpp.o -c /mnt/d/competitive-programming-code/cpp/AOJ/aaabbb.cpp

CMakeFiles/aaabbb.dir/aaabbb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aaabbb.dir/aaabbb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/competitive-programming-code/cpp/AOJ/aaabbb.cpp > CMakeFiles/aaabbb.dir/aaabbb.cpp.i

CMakeFiles/aaabbb.dir/aaabbb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aaabbb.dir/aaabbb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/competitive-programming-code/cpp/AOJ/aaabbb.cpp -o CMakeFiles/aaabbb.dir/aaabbb.cpp.s

CMakeFiles/aaabbb.dir/aaabbb.cpp.o.requires:

.PHONY : CMakeFiles/aaabbb.dir/aaabbb.cpp.o.requires

CMakeFiles/aaabbb.dir/aaabbb.cpp.o.provides: CMakeFiles/aaabbb.dir/aaabbb.cpp.o.requires
	$(MAKE) -f CMakeFiles/aaabbb.dir/build.make CMakeFiles/aaabbb.dir/aaabbb.cpp.o.provides.build
.PHONY : CMakeFiles/aaabbb.dir/aaabbb.cpp.o.provides

CMakeFiles/aaabbb.dir/aaabbb.cpp.o.provides.build: CMakeFiles/aaabbb.dir/aaabbb.cpp.o


# Object files for target aaabbb
aaabbb_OBJECTS = \
"CMakeFiles/aaabbb.dir/aaabbb.cpp.o"

# External object files for target aaabbb
aaabbb_EXTERNAL_OBJECTS =

aaabbb: CMakeFiles/aaabbb.dir/aaabbb.cpp.o
aaabbb: CMakeFiles/aaabbb.dir/build.make
aaabbb: CMakeFiles/aaabbb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aaabbb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aaabbb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aaabbb.dir/build: aaabbb

.PHONY : CMakeFiles/aaabbb.dir/build

CMakeFiles/aaabbb.dir/requires: CMakeFiles/aaabbb.dir/aaabbb.cpp.o.requires

.PHONY : CMakeFiles/aaabbb.dir/requires

CMakeFiles/aaabbb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aaabbb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aaabbb.dir/clean

CMakeFiles/aaabbb.dir/depend:
	cd /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/competitive-programming-code/cpp/AOJ /mnt/d/competitive-programming-code/cpp/AOJ /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug /mnt/d/competitive-programming-code/cpp/AOJ/cmake-build-debug/CMakeFiles/aaabbb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aaabbb.dir/depend

