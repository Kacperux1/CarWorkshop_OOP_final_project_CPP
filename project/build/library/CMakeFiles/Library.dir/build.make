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
CMAKE_SOURCE_DIR = /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build

# Include any dependencies generated for this target.
include library/CMakeFiles/Library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include library/CMakeFiles/Library.dir/compiler_depend.make

# Include the progress variables for this target.
include library/CMakeFiles/Library.dir/progress.make

# Include the compile flags for this target's objects.
include library/CMakeFiles/Library.dir/flags.make

library/CMakeFiles/Library.dir/src/model/Client.cpp.o: library/CMakeFiles/Library.dir/flags.make
library/CMakeFiles/Library.dir/src/model/Client.cpp.o: /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Client.cpp
library/CMakeFiles/Library.dir/src/model/Client.cpp.o: library/CMakeFiles/Library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object library/CMakeFiles/Library.dir/src/model/Client.cpp.o"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/Library.dir/src/model/Client.cpp.o -MF CMakeFiles/Library.dir/src/model/Client.cpp.o.d -o CMakeFiles/Library.dir/src/model/Client.cpp.o -c /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Client.cpp

library/CMakeFiles/Library.dir/src/model/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Library.dir/src/model/Client.cpp.i"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Client.cpp > CMakeFiles/Library.dir/src/model/Client.cpp.i

library/CMakeFiles/Library.dir/src/model/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Library.dir/src/model/Client.cpp.s"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Client.cpp -o CMakeFiles/Library.dir/src/model/Client.cpp.s

library/CMakeFiles/Library.dir/src/model/Address.cpp.o: library/CMakeFiles/Library.dir/flags.make
library/CMakeFiles/Library.dir/src/model/Address.cpp.o: /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Address.cpp
library/CMakeFiles/Library.dir/src/model/Address.cpp.o: library/CMakeFiles/Library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object library/CMakeFiles/Library.dir/src/model/Address.cpp.o"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/Library.dir/src/model/Address.cpp.o -MF CMakeFiles/Library.dir/src/model/Address.cpp.o.d -o CMakeFiles/Library.dir/src/model/Address.cpp.o -c /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Address.cpp

library/CMakeFiles/Library.dir/src/model/Address.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Library.dir/src/model/Address.cpp.i"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Address.cpp > CMakeFiles/Library.dir/src/model/Address.cpp.i

library/CMakeFiles/Library.dir/src/model/Address.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Library.dir/src/model/Address.cpp.s"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Address.cpp -o CMakeFiles/Library.dir/src/model/Address.cpp.s

library/CMakeFiles/Library.dir/src/model/Vehicle.cpp.o: library/CMakeFiles/Library.dir/flags.make
library/CMakeFiles/Library.dir/src/model/Vehicle.cpp.o: /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Vehicle.cpp
library/CMakeFiles/Library.dir/src/model/Vehicle.cpp.o: library/CMakeFiles/Library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object library/CMakeFiles/Library.dir/src/model/Vehicle.cpp.o"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/Library.dir/src/model/Vehicle.cpp.o -MF CMakeFiles/Library.dir/src/model/Vehicle.cpp.o.d -o CMakeFiles/Library.dir/src/model/Vehicle.cpp.o -c /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Vehicle.cpp

library/CMakeFiles/Library.dir/src/model/Vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Library.dir/src/model/Vehicle.cpp.i"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Vehicle.cpp > CMakeFiles/Library.dir/src/model/Vehicle.cpp.i

library/CMakeFiles/Library.dir/src/model/Vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Library.dir/src/model/Vehicle.cpp.s"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Vehicle.cpp -o CMakeFiles/Library.dir/src/model/Vehicle.cpp.s

library/CMakeFiles/Library.dir/src/model/Rent.cpp.o: library/CMakeFiles/Library.dir/flags.make
library/CMakeFiles/Library.dir/src/model/Rent.cpp.o: /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Rent.cpp
library/CMakeFiles/Library.dir/src/model/Rent.cpp.o: library/CMakeFiles/Library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object library/CMakeFiles/Library.dir/src/model/Rent.cpp.o"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/Library.dir/src/model/Rent.cpp.o -MF CMakeFiles/Library.dir/src/model/Rent.cpp.o.d -o CMakeFiles/Library.dir/src/model/Rent.cpp.o -c /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Rent.cpp

library/CMakeFiles/Library.dir/src/model/Rent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Library.dir/src/model/Rent.cpp.i"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Rent.cpp > CMakeFiles/Library.dir/src/model/Rent.cpp.i

library/CMakeFiles/Library.dir/src/model/Rent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Library.dir/src/model/Rent.cpp.s"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/src/model/Rent.cpp -o CMakeFiles/Library.dir/src/model/Rent.cpp.s

library/CMakeFiles/Library.dir/test/RentTester.cpp.o: library/CMakeFiles/Library.dir/flags.make
library/CMakeFiles/Library.dir/test/RentTester.cpp.o: /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/test/RentTester.cpp
library/CMakeFiles/Library.dir/test/RentTester.cpp.o: library/CMakeFiles/Library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object library/CMakeFiles/Library.dir/test/RentTester.cpp.o"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/Library.dir/test/RentTester.cpp.o -MF CMakeFiles/Library.dir/test/RentTester.cpp.o.d -o CMakeFiles/Library.dir/test/RentTester.cpp.o -c /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/test/RentTester.cpp

library/CMakeFiles/Library.dir/test/RentTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Library.dir/test/RentTester.cpp.i"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/test/RentTester.cpp > CMakeFiles/Library.dir/test/RentTester.cpp.i

library/CMakeFiles/Library.dir/test/RentTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Library.dir/test/RentTester.cpp.s"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/test/RentTester.cpp -o CMakeFiles/Library.dir/test/RentTester.cpp.s

library/CMakeFiles/Library.dir/test/AddressTester.cpp.o: library/CMakeFiles/Library.dir/flags.make
library/CMakeFiles/Library.dir/test/AddressTester.cpp.o: /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/test/AddressTester.cpp
library/CMakeFiles/Library.dir/test/AddressTester.cpp.o: library/CMakeFiles/Library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object library/CMakeFiles/Library.dir/test/AddressTester.cpp.o"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT library/CMakeFiles/Library.dir/test/AddressTester.cpp.o -MF CMakeFiles/Library.dir/test/AddressTester.cpp.o.d -o CMakeFiles/Library.dir/test/AddressTester.cpp.o -c /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/test/AddressTester.cpp

library/CMakeFiles/Library.dir/test/AddressTester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Library.dir/test/AddressTester.cpp.i"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/test/AddressTester.cpp > CMakeFiles/Library.dir/test/AddressTester.cpp.i

library/CMakeFiles/Library.dir/test/AddressTester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Library.dir/test/AddressTester.cpp.s"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library/test/AddressTester.cpp -o CMakeFiles/Library.dir/test/AddressTester.cpp.s

# Object files for target Library
Library_OBJECTS = \
"CMakeFiles/Library.dir/src/model/Client.cpp.o" \
"CMakeFiles/Library.dir/src/model/Address.cpp.o" \
"CMakeFiles/Library.dir/src/model/Vehicle.cpp.o" \
"CMakeFiles/Library.dir/src/model/Rent.cpp.o" \
"CMakeFiles/Library.dir/test/RentTester.cpp.o" \
"CMakeFiles/Library.dir/test/AddressTester.cpp.o"

# External object files for target Library
Library_EXTERNAL_OBJECTS =

library/libLibrary.a: library/CMakeFiles/Library.dir/src/model/Client.cpp.o
library/libLibrary.a: library/CMakeFiles/Library.dir/src/model/Address.cpp.o
library/libLibrary.a: library/CMakeFiles/Library.dir/src/model/Vehicle.cpp.o
library/libLibrary.a: library/CMakeFiles/Library.dir/src/model/Rent.cpp.o
library/libLibrary.a: library/CMakeFiles/Library.dir/test/RentTester.cpp.o
library/libLibrary.a: library/CMakeFiles/Library.dir/test/AddressTester.cpp.o
library/libLibrary.a: library/CMakeFiles/Library.dir/build.make
library/libLibrary.a: library/CMakeFiles/Library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libLibrary.a"
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && $(CMAKE_COMMAND) -P CMakeFiles/Library.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
library/CMakeFiles/Library.dir/build: library/libLibrary.a
.PHONY : library/CMakeFiles/Library.dir/build

library/CMakeFiles/Library.dir/clean:
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library && $(CMAKE_COMMAND) -P CMakeFiles/Library.dir/cmake_clean.cmake
.PHONY : library/CMakeFiles/Library.dir/clean

library/CMakeFiles/Library.dir/depend:
	cd /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/library /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library /mnt/c/Users/andrz/CLionProjects/Warsztaty/maziarz/workshop/build/library/CMakeFiles/Library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : library/CMakeFiles/Library.dir/depend

