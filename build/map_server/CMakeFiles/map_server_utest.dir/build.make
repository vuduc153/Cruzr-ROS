# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/cruiser/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cruiser/catkin_ws/build

# Include any dependencies generated for this target.
include map_server/CMakeFiles/map_server_utest.dir/depend.make

# Include the progress variables for this target.
include map_server/CMakeFiles/map_server_utest.dir/progress.make

# Include the compile flags for this target's objects.
include map_server/CMakeFiles/map_server_utest.dir/flags.make

map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o: map_server/CMakeFiles/map_server_utest.dir/flags.make
map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o: /home/cruiser/catkin_ws/src/map_server/test/utest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cruiser/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o"
	cd /home/cruiser/catkin_ws/build/map_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/map_server_utest.dir/test/utest.cpp.o -c /home/cruiser/catkin_ws/src/map_server/test/utest.cpp

map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/map_server_utest.dir/test/utest.cpp.i"
	cd /home/cruiser/catkin_ws/build/map_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cruiser/catkin_ws/src/map_server/test/utest.cpp > CMakeFiles/map_server_utest.dir/test/utest.cpp.i

map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/map_server_utest.dir/test/utest.cpp.s"
	cd /home/cruiser/catkin_ws/build/map_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cruiser/catkin_ws/src/map_server/test/utest.cpp -o CMakeFiles/map_server_utest.dir/test/utest.cpp.s

map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o.requires:
.PHONY : map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o.requires

map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o.provides: map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o.requires
	$(MAKE) -f map_server/CMakeFiles/map_server_utest.dir/build.make map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o.provides.build
.PHONY : map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o.provides

map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o.provides.build: map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o

map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o: map_server/CMakeFiles/map_server_utest.dir/flags.make
map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o: /home/cruiser/catkin_ws/src/map_server/test/test_constants.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cruiser/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o"
	cd /home/cruiser/catkin_ws/build/map_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o -c /home/cruiser/catkin_ws/src/map_server/test/test_constants.cpp

map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/map_server_utest.dir/test/test_constants.cpp.i"
	cd /home/cruiser/catkin_ws/build/map_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/cruiser/catkin_ws/src/map_server/test/test_constants.cpp > CMakeFiles/map_server_utest.dir/test/test_constants.cpp.i

map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/map_server_utest.dir/test/test_constants.cpp.s"
	cd /home/cruiser/catkin_ws/build/map_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/cruiser/catkin_ws/src/map_server/test/test_constants.cpp -o CMakeFiles/map_server_utest.dir/test/test_constants.cpp.s

map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o.requires:
.PHONY : map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o.requires

map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o.provides: map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o.requires
	$(MAKE) -f map_server/CMakeFiles/map_server_utest.dir/build.make map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o.provides.build
.PHONY : map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o.provides

map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o.provides.build: map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o

# Object files for target map_server_utest
map_server_utest_OBJECTS = \
"CMakeFiles/map_server_utest.dir/test/utest.cpp.o" \
"CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o"

# External object files for target map_server_utest
map_server_utest_EXTERNAL_OBJECTS =

/home/cruiser/catkin_ws/devel/lib/map_server/map_server_utest: map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o
/home/cruiser/catkin_ws/devel/lib/map_server/map_server_utest: map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o
/home/cruiser/catkin_ws/devel/lib/map_server/map_server_utest: map_server/CMakeFiles/map_server_utest.dir/build.make
/home/cruiser/catkin_ws/devel/lib/map_server/map_server_utest: gtest/libgtest.so
/home/cruiser/catkin_ws/devel/lib/map_server/map_server_utest: /home/cruiser/catkin_ws/devel/lib/libimage_loader.so
/home/cruiser/catkin_ws/devel/lib/map_server/map_server_utest: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/cruiser/catkin_ws/devel/lib/map_server/map_server_utest: map_server/CMakeFiles/map_server_utest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/cruiser/catkin_ws/devel/lib/map_server/map_server_utest"
	cd /home/cruiser/catkin_ws/build/map_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/map_server_utest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
map_server/CMakeFiles/map_server_utest.dir/build: /home/cruiser/catkin_ws/devel/lib/map_server/map_server_utest
.PHONY : map_server/CMakeFiles/map_server_utest.dir/build

map_server/CMakeFiles/map_server_utest.dir/requires: map_server/CMakeFiles/map_server_utest.dir/test/utest.cpp.o.requires
map_server/CMakeFiles/map_server_utest.dir/requires: map_server/CMakeFiles/map_server_utest.dir/test/test_constants.cpp.o.requires
.PHONY : map_server/CMakeFiles/map_server_utest.dir/requires

map_server/CMakeFiles/map_server_utest.dir/clean:
	cd /home/cruiser/catkin_ws/build/map_server && $(CMAKE_COMMAND) -P CMakeFiles/map_server_utest.dir/cmake_clean.cmake
.PHONY : map_server/CMakeFiles/map_server_utest.dir/clean

map_server/CMakeFiles/map_server_utest.dir/depend:
	cd /home/cruiser/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cruiser/catkin_ws/src /home/cruiser/catkin_ws/src/map_server /home/cruiser/catkin_ws/build /home/cruiser/catkin_ws/build/map_server /home/cruiser/catkin_ws/build/map_server/CMakeFiles/map_server_utest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : map_server/CMakeFiles/map_server_utest.dir/depend

