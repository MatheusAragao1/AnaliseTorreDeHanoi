# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /cygdrive/c/Users/fifap/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/fifap/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AnaliseTorreDeHanoi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AnaliseTorreDeHanoi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AnaliseTorreDeHanoi.dir/flags.make

CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.o: CMakeFiles/AnaliseTorreDeHanoi.dir/flags.make
CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.o: ../torreDeHanoiRecursiva.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.o   -c /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/torreDeHanoiRecursiva.c

CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/torreDeHanoiRecursiva.c > CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.i

CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/torreDeHanoiRecursiva.c -o CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.s

# Object files for target AnaliseTorreDeHanoi
AnaliseTorreDeHanoi_OBJECTS = \
"CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.o"

# External object files for target AnaliseTorreDeHanoi
AnaliseTorreDeHanoi_EXTERNAL_OBJECTS =

AnaliseTorreDeHanoi.exe: CMakeFiles/AnaliseTorreDeHanoi.dir/torreDeHanoiRecursiva.c.o
AnaliseTorreDeHanoi.exe: CMakeFiles/AnaliseTorreDeHanoi.dir/build.make
AnaliseTorreDeHanoi.exe: CMakeFiles/AnaliseTorreDeHanoi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable AnaliseTorreDeHanoi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AnaliseTorreDeHanoi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AnaliseTorreDeHanoi.dir/build: AnaliseTorreDeHanoi.exe

.PHONY : CMakeFiles/AnaliseTorreDeHanoi.dir/build

CMakeFiles/AnaliseTorreDeHanoi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AnaliseTorreDeHanoi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AnaliseTorreDeHanoi.dir/clean

CMakeFiles/AnaliseTorreDeHanoi.dir/depend:
	cd /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/cmake-build-debug /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/cmake-build-debug /cygdrive/c/Users/fifap/CLionProjects/AnaliseTorreDeHanoi/Recursivo/cmake-build-debug/CMakeFiles/AnaliseTorreDeHanoi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AnaliseTorreDeHanoi.dir/depend

