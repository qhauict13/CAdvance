# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/joel/Desktop/C Advance/Ginz"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/joel/Desktop/C Advance/Ginz"

# Include any dependencies generated for this target.
include week04/CMakeFiles/week04.dir/depend.make

# Include the progress variables for this target.
include week04/CMakeFiles/week04.dir/progress.make

# Include the compile flags for this target's objects.
include week04/CMakeFiles/week04.dir/flags.make

week04/CMakeFiles/week04.dir/test_lib.c.o: week04/CMakeFiles/week04.dir/flags.make
week04/CMakeFiles/week04.dir/test_lib.c.o: week04/test_lib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/joel/Desktop/C Advance/Ginz/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object week04/CMakeFiles/week04.dir/test_lib.c.o"
	cd "/home/joel/Desktop/C Advance/Ginz/week04" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/week04.dir/test_lib.c.o   -c "/home/joel/Desktop/C Advance/Ginz/week04/test_lib.c"

week04/CMakeFiles/week04.dir/test_lib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/week04.dir/test_lib.c.i"
	cd "/home/joel/Desktop/C Advance/Ginz/week04" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/joel/Desktop/C Advance/Ginz/week04/test_lib.c" > CMakeFiles/week04.dir/test_lib.c.i

week04/CMakeFiles/week04.dir/test_lib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/week04.dir/test_lib.c.s"
	cd "/home/joel/Desktop/C Advance/Ginz/week04" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/joel/Desktop/C Advance/Ginz/week04/test_lib.c" -o CMakeFiles/week04.dir/test_lib.c.s

week04/CMakeFiles/week04.dir/test_lib.c.o.requires:

.PHONY : week04/CMakeFiles/week04.dir/test_lib.c.o.requires

week04/CMakeFiles/week04.dir/test_lib.c.o.provides: week04/CMakeFiles/week04.dir/test_lib.c.o.requires
	$(MAKE) -f week04/CMakeFiles/week04.dir/build.make week04/CMakeFiles/week04.dir/test_lib.c.o.provides.build
.PHONY : week04/CMakeFiles/week04.dir/test_lib.c.o.provides

week04/CMakeFiles/week04.dir/test_lib.c.o.provides.build: week04/CMakeFiles/week04.dir/test_lib.c.o


# Object files for target week04
week04_OBJECTS = \
"CMakeFiles/week04.dir/test_lib.c.o"

# External object files for target week04
week04_EXTERNAL_OBJECTS =

week04/week04: week04/CMakeFiles/week04.dir/test_lib.c.o
week04/week04: week04/CMakeFiles/week04.dir/build.make
week04/week04: week04/CMakeFiles/week04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/joel/Desktop/C Advance/Ginz/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable week04"
	cd "/home/joel/Desktop/C Advance/Ginz/week04" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/week04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
week04/CMakeFiles/week04.dir/build: week04/week04

.PHONY : week04/CMakeFiles/week04.dir/build

week04/CMakeFiles/week04.dir/requires: week04/CMakeFiles/week04.dir/test_lib.c.o.requires

.PHONY : week04/CMakeFiles/week04.dir/requires

week04/CMakeFiles/week04.dir/clean:
	cd "/home/joel/Desktop/C Advance/Ginz/week04" && $(CMAKE_COMMAND) -P CMakeFiles/week04.dir/cmake_clean.cmake
.PHONY : week04/CMakeFiles/week04.dir/clean

week04/CMakeFiles/week04.dir/depend:
	cd "/home/joel/Desktop/C Advance/Ginz" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/joel/Desktop/C Advance/Ginz" "/home/joel/Desktop/C Advance/Ginz/week04" "/home/joel/Desktop/C Advance/Ginz" "/home/joel/Desktop/C Advance/Ginz/week04" "/home/joel/Desktop/C Advance/Ginz/week04/CMakeFiles/week04.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : week04/CMakeFiles/week04.dir/depend

