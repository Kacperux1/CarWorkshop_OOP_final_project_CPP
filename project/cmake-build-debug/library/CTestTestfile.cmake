# CMake generated Testfile for 
# Source directory: /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library
# Build directory: /mnt/c/Users/andrz/CLionProjects/Warsztaty/project/cmake-build-debug/library
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(LibraryTest "LibraryTester" "--report_level=detailed" "--log_level=all" "--color_output=yes")
set_tests_properties(LibraryTest PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/CMakeLists.txt;133;add_test;/mnt/c/Users/andrz/CLionProjects/Warsztaty/project/library/CMakeLists.txt;0;")
subdirs("cereal")
