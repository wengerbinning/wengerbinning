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
CMAKE_SOURCE_DIR = /home/wbzheng/c/demo/memory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wbzheng/c/demo/memory/build

# Include any dependencies generated for this target.
include CMakeFiles/demo-memory-allocation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo-memory-allocation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo-memory-allocation.dir/flags.make

CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.o: CMakeFiles/demo-memory-allocation.dir/flags.make
CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.o: ../demo-memory-allocation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wbzheng/c/demo/memory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.o   -c /home/wbzheng/c/demo/memory/demo-memory-allocation.c

CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wbzheng/c/demo/memory/demo-memory-allocation.c > CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.i

CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wbzheng/c/demo/memory/demo-memory-allocation.c -o CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.s

# Object files for target demo-memory-allocation
demo__memory__allocation_OBJECTS = \
"CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.o"

# External object files for target demo-memory-allocation
demo__memory__allocation_EXTERNAL_OBJECTS =

../demo-memory-allocation: CMakeFiles/demo-memory-allocation.dir/demo-memory-allocation.c.o
../demo-memory-allocation: CMakeFiles/demo-memory-allocation.dir/build.make
../demo-memory-allocation: CMakeFiles/demo-memory-allocation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wbzheng/c/demo/memory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../demo-memory-allocation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo-memory-allocation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo-memory-allocation.dir/build: ../demo-memory-allocation

.PHONY : CMakeFiles/demo-memory-allocation.dir/build

CMakeFiles/demo-memory-allocation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo-memory-allocation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo-memory-allocation.dir/clean

CMakeFiles/demo-memory-allocation.dir/depend:
	cd /home/wbzheng/c/demo/memory/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wbzheng/c/demo/memory /home/wbzheng/c/demo/memory /home/wbzheng/c/demo/memory/build /home/wbzheng/c/demo/memory/build /home/wbzheng/c/demo/memory/build/CMakeFiles/demo-memory-allocation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo-memory-allocation.dir/depend

