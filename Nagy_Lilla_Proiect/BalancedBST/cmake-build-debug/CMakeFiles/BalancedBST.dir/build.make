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
CMAKE_SOURCE_DIR = /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BalancedBST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BalancedBST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BalancedBST.dir/flags.make

CMakeFiles/BalancedBST.dir/main.c.o: CMakeFiles/BalancedBST.dir/flags.make
CMakeFiles/BalancedBST.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BalancedBST.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BalancedBST.dir/main.c.o   -c /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/main.c

CMakeFiles/BalancedBST.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BalancedBST.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/main.c > CMakeFiles/BalancedBST.dir/main.c.i

CMakeFiles/BalancedBST.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BalancedBST.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/main.c -o CMakeFiles/BalancedBST.dir/main.c.s

CMakeFiles/BalancedBST.dir/main.c.o.requires:

.PHONY : CMakeFiles/BalancedBST.dir/main.c.o.requires

CMakeFiles/BalancedBST.dir/main.c.o.provides: CMakeFiles/BalancedBST.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/BalancedBST.dir/build.make CMakeFiles/BalancedBST.dir/main.c.o.provides.build
.PHONY : CMakeFiles/BalancedBST.dir/main.c.o.provides

CMakeFiles/BalancedBST.dir/main.c.o.provides.build: CMakeFiles/BalancedBST.dir/main.c.o


CMakeFiles/BalancedBST.dir/BalancedBST.c.o: CMakeFiles/BalancedBST.dir/flags.make
CMakeFiles/BalancedBST.dir/BalancedBST.c.o: ../BalancedBST.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BalancedBST.dir/BalancedBST.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/BalancedBST.dir/BalancedBST.c.o   -c /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/BalancedBST.c

CMakeFiles/BalancedBST.dir/BalancedBST.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BalancedBST.dir/BalancedBST.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/BalancedBST.c > CMakeFiles/BalancedBST.dir/BalancedBST.c.i

CMakeFiles/BalancedBST.dir/BalancedBST.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BalancedBST.dir/BalancedBST.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/BalancedBST.c -o CMakeFiles/BalancedBST.dir/BalancedBST.c.s

CMakeFiles/BalancedBST.dir/BalancedBST.c.o.requires:

.PHONY : CMakeFiles/BalancedBST.dir/BalancedBST.c.o.requires

CMakeFiles/BalancedBST.dir/BalancedBST.c.o.provides: CMakeFiles/BalancedBST.dir/BalancedBST.c.o.requires
	$(MAKE) -f CMakeFiles/BalancedBST.dir/build.make CMakeFiles/BalancedBST.dir/BalancedBST.c.o.provides.build
.PHONY : CMakeFiles/BalancedBST.dir/BalancedBST.c.o.provides

CMakeFiles/BalancedBST.dir/BalancedBST.c.o.provides.build: CMakeFiles/BalancedBST.dir/BalancedBST.c.o


# Object files for target BalancedBST
BalancedBST_OBJECTS = \
"CMakeFiles/BalancedBST.dir/main.c.o" \
"CMakeFiles/BalancedBST.dir/BalancedBST.c.o"

# External object files for target BalancedBST
BalancedBST_EXTERNAL_OBJECTS =

BalancedBST: CMakeFiles/BalancedBST.dir/main.c.o
BalancedBST: CMakeFiles/BalancedBST.dir/BalancedBST.c.o
BalancedBST: CMakeFiles/BalancedBST.dir/build.make
BalancedBST: CMakeFiles/BalancedBST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable BalancedBST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BalancedBST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BalancedBST.dir/build: BalancedBST

.PHONY : CMakeFiles/BalancedBST.dir/build

CMakeFiles/BalancedBST.dir/requires: CMakeFiles/BalancedBST.dir/main.c.o.requires
CMakeFiles/BalancedBST.dir/requires: CMakeFiles/BalancedBST.dir/BalancedBST.c.o.requires

.PHONY : CMakeFiles/BalancedBST.dir/requires

CMakeFiles/BalancedBST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BalancedBST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BalancedBST.dir/clean

CMakeFiles/BalancedBST.dir/depend:
	cd /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/cmake-build-debug /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/cmake-build-debug /home/lilla/Desktop/BitDefenderC/Nagy_Lilla_Proiect/BalancedBST/cmake-build-debug/CMakeFiles/BalancedBST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BalancedBST.dir/depend

