# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/lilla/clion-2016.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/lilla/clion-2016.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lilla/Desktop/BitDefenderC/libds

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilla/Desktop/BitDefenderC/libds/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/libds.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libds.dir/flags.make

CMakeFiles/libds.dir/Vector.c.o: CMakeFiles/libds.dir/flags.make
CMakeFiles/libds.dir/Vector.c.o: ../Vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilla/Desktop/BitDefenderC/libds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/libds.dir/Vector.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/libds.dir/Vector.c.o   -c /home/lilla/Desktop/BitDefenderC/libds/Vector.c

CMakeFiles/libds.dir/Vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libds.dir/Vector.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lilla/Desktop/BitDefenderC/libds/Vector.c > CMakeFiles/libds.dir/Vector.c.i

CMakeFiles/libds.dir/Vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libds.dir/Vector.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lilla/Desktop/BitDefenderC/libds/Vector.c -o CMakeFiles/libds.dir/Vector.c.s

CMakeFiles/libds.dir/Vector.c.o.requires:

.PHONY : CMakeFiles/libds.dir/Vector.c.o.requires

CMakeFiles/libds.dir/Vector.c.o.provides: CMakeFiles/libds.dir/Vector.c.o.requires
	$(MAKE) -f CMakeFiles/libds.dir/build.make CMakeFiles/libds.dir/Vector.c.o.provides.build
.PHONY : CMakeFiles/libds.dir/Vector.c.o.provides

CMakeFiles/libds.dir/Vector.c.o.provides.build: CMakeFiles/libds.dir/Vector.c.o


# Object files for target libds
libds_OBJECTS = \
"CMakeFiles/libds.dir/Vector.c.o"

# External object files for target libds
libds_EXTERNAL_OBJECTS =

liblibds.a: CMakeFiles/libds.dir/Vector.c.o
liblibds.a: CMakeFiles/libds.dir/build.make
liblibds.a: CMakeFiles/libds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilla/Desktop/BitDefenderC/libds/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library liblibds.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libds.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libds.dir/build: liblibds.a

.PHONY : CMakeFiles/libds.dir/build

CMakeFiles/libds.dir/requires: CMakeFiles/libds.dir/Vector.c.o.requires

.PHONY : CMakeFiles/libds.dir/requires

CMakeFiles/libds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libds.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libds.dir/clean

CMakeFiles/libds.dir/depend:
	cd /home/lilla/Desktop/BitDefenderC/libds/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilla/Desktop/BitDefenderC/libds /home/lilla/Desktop/BitDefenderC/libds /home/lilla/Desktop/BitDefenderC/libds/cmake-build-debug /home/lilla/Desktop/BitDefenderC/libds/cmake-build-debug /home/lilla/Desktop/BitDefenderC/libds/cmake-build-debug/CMakeFiles/libds.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libds.dir/depend

