# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/andrz/CLionProjects/Warsztaty/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug

# Include any dependencies generated for this target.
include library/cereal/sandbox/CMakeFiles/performance.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include library/cereal/sandbox/CMakeFiles/performance.dir/compiler_depend.make

# Include the progress variables for this target.
include library/cereal/sandbox/CMakeFiles/performance.dir/progress.make

# Include the compile flags for this target's objects.
include library/cereal/sandbox/CMakeFiles/performance.dir/flags.make

library/cereal/sandbox/CMakeFiles/performance.dir/performance.cpp.o: library/cereal/sandbox/CMakeFiles/performance.dir/flags.make
library/cereal/sandbox/CMakeFiles/performance.dir/performance.cpp.o: /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/cereal/sandbox/performance.cpp
library/cereal/sandbox/CMakeFiles/performance.dir/performance.cpp.o: library/cereal/sandbox/CMakeFiles/performance.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object library/cereal/sandbox/CMakeFiles/performance.dir/performance.cpp.o"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/library/cereal/sandbox && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/cereal/sandbox/CMakeFiles/performance.dir/performance.cpp.o -MF CMakeFiles/performance.dir/performance.cpp.o.d -o CMakeFiles/performance.dir/performance.cpp.o -c /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/cereal/sandbox/performance.cpp

library/cereal/sandbox/CMakeFiles/performance.dir/performance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/performance.dir/performance.cpp.i"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/library/cereal/sandbox && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/cereal/sandbox/performance.cpp > CMakeFiles/performance.dir/performance.cpp.i

library/cereal/sandbox/CMakeFiles/performance.dir/performance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/performance.dir/performance.cpp.s"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/library/cereal/sandbox && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/cereal/sandbox/performance.cpp -o CMakeFiles/performance.dir/performance.cpp.s

# Object files for target performance
performance_OBJECTS = \
"CMakeFiles/performance.dir/performance.cpp.o"

# External object files for target performance
performance_EXTERNAL_OBJECTS =

library/cereal/sandbox/performance: library/cereal/sandbox/CMakeFiles/performance.dir/performance.cpp.o
library/cereal/sandbox/performance: library/cereal/sandbox/CMakeFiles/performance.dir/build.make
library/cereal/sandbox/performance: /usr/lib/x86_64-linux-gnu/libboost_serialization.so.1.74.0
library/cereal/sandbox/performance: library/cereal/sandbox/CMakeFiles/performance.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable performance"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/library/cereal/sandbox && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/performance.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
library/cereal/sandbox/CMakeFiles/performance.dir/build: library/cereal/sandbox/performance
.PHONY : library/cereal/sandbox/CMakeFiles/performance.dir/build

library/cereal/sandbox/CMakeFiles/performance.dir/clean:
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/library/cereal/sandbox && $(CMAKE_COMMAND) -P CMakeFiles/performance.dir/cmake_clean.cmake
.PHONY : library/cereal/sandbox/CMakeFiles/performance.dir/clean

library/cereal/sandbox/CMakeFiles/performance.dir/depend:
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/andrz/CLionProjects/Warsztaty/project /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/cereal/sandbox /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/library/cereal/sandbox /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/library/cereal/sandbox/CMakeFiles/performance.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : library/cereal/sandbox/CMakeFiles/performance.dir/depend

