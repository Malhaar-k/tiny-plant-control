# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/malhaar-k/vscode-projects/cpp_tfSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/malhaar-k/vscode-projects/cpp_tfSim/build

# Include any dependencies generated for this target.
include CMakeFiles/tfSim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tfSim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tfSim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tfSim.dir/flags.make

CMakeFiles/tfSim.dir/lib/matrix_helper.c.o: CMakeFiles/tfSim.dir/flags.make
CMakeFiles/tfSim.dir/lib/matrix_helper.c.o: /home/malhaar-k/vscode-projects/cpp_tfSim/lib/matrix_helper.c
CMakeFiles/tfSim.dir/lib/matrix_helper.c.o: CMakeFiles/tfSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/malhaar-k/vscode-projects/cpp_tfSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tfSim.dir/lib/matrix_helper.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tfSim.dir/lib/matrix_helper.c.o -MF CMakeFiles/tfSim.dir/lib/matrix_helper.c.o.d -o CMakeFiles/tfSim.dir/lib/matrix_helper.c.o -c /home/malhaar-k/vscode-projects/cpp_tfSim/lib/matrix_helper.c

CMakeFiles/tfSim.dir/lib/matrix_helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/tfSim.dir/lib/matrix_helper.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/malhaar-k/vscode-projects/cpp_tfSim/lib/matrix_helper.c > CMakeFiles/tfSim.dir/lib/matrix_helper.c.i

CMakeFiles/tfSim.dir/lib/matrix_helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/tfSim.dir/lib/matrix_helper.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/malhaar-k/vscode-projects/cpp_tfSim/lib/matrix_helper.c -o CMakeFiles/tfSim.dir/lib/matrix_helper.c.s

CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.o: CMakeFiles/tfSim.dir/flags.make
CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.o: /home/malhaar-k/vscode-projects/cpp_tfSim/lib/tf_descrete.cpp
CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.o: CMakeFiles/tfSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/malhaar-k/vscode-projects/cpp_tfSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.o -MF CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.o.d -o CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.o -c /home/malhaar-k/vscode-projects/cpp_tfSim/lib/tf_descrete.cpp

CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malhaar-k/vscode-projects/cpp_tfSim/lib/tf_descrete.cpp > CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.i

CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malhaar-k/vscode-projects/cpp_tfSim/lib/tf_descrete.cpp -o CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.s

CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.o: CMakeFiles/tfSim.dir/flags.make
CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.o: /home/malhaar-k/vscode-projects/cpp_tfSim/lib/tf_statespace.cpp
CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.o: CMakeFiles/tfSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/malhaar-k/vscode-projects/cpp_tfSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.o -MF CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.o.d -o CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.o -c /home/malhaar-k/vscode-projects/cpp_tfSim/lib/tf_statespace.cpp

CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malhaar-k/vscode-projects/cpp_tfSim/lib/tf_statespace.cpp > CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.i

CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malhaar-k/vscode-projects/cpp_tfSim/lib/tf_statespace.cpp -o CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.s

CMakeFiles/tfSim.dir/src/main.cpp.o: CMakeFiles/tfSim.dir/flags.make
CMakeFiles/tfSim.dir/src/main.cpp.o: /home/malhaar-k/vscode-projects/cpp_tfSim/src/main.cpp
CMakeFiles/tfSim.dir/src/main.cpp.o: CMakeFiles/tfSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/malhaar-k/vscode-projects/cpp_tfSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tfSim.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tfSim.dir/src/main.cpp.o -MF CMakeFiles/tfSim.dir/src/main.cpp.o.d -o CMakeFiles/tfSim.dir/src/main.cpp.o -c /home/malhaar-k/vscode-projects/cpp_tfSim/src/main.cpp

CMakeFiles/tfSim.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tfSim.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malhaar-k/vscode-projects/cpp_tfSim/src/main.cpp > CMakeFiles/tfSim.dir/src/main.cpp.i

CMakeFiles/tfSim.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tfSim.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malhaar-k/vscode-projects/cpp_tfSim/src/main.cpp -o CMakeFiles/tfSim.dir/src/main.cpp.s

# Object files for target tfSim
tfSim_OBJECTS = \
"CMakeFiles/tfSim.dir/lib/matrix_helper.c.o" \
"CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.o" \
"CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.o" \
"CMakeFiles/tfSim.dir/src/main.cpp.o"

# External object files for target tfSim
tfSim_EXTERNAL_OBJECTS =

tfSim: CMakeFiles/tfSim.dir/lib/matrix_helper.c.o
tfSim: CMakeFiles/tfSim.dir/lib/tf_descrete.cpp.o
tfSim: CMakeFiles/tfSim.dir/lib/tf_statespace.cpp.o
tfSim: CMakeFiles/tfSim.dir/src/main.cpp.o
tfSim: CMakeFiles/tfSim.dir/build.make
tfSim: CMakeFiles/tfSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/malhaar-k/vscode-projects/cpp_tfSim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable tfSim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tfSim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tfSim.dir/build: tfSim
.PHONY : CMakeFiles/tfSim.dir/build

CMakeFiles/tfSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tfSim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tfSim.dir/clean

CMakeFiles/tfSim.dir/depend:
	cd /home/malhaar-k/vscode-projects/cpp_tfSim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/malhaar-k/vscode-projects/cpp_tfSim /home/malhaar-k/vscode-projects/cpp_tfSim /home/malhaar-k/vscode-projects/cpp_tfSim/build /home/malhaar-k/vscode-projects/cpp_tfSim/build /home/malhaar-k/vscode-projects/cpp_tfSim/build/CMakeFiles/tfSim.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tfSim.dir/depend

