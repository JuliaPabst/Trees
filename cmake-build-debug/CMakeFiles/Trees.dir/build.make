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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/petrascheuer/Desktop/Trees

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/petrascheuer/Desktop/Trees/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Trees.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Trees.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Trees.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Trees.dir/flags.make

CMakeFiles/Trees.dir/main.cpp.o: CMakeFiles/Trees.dir/flags.make
CMakeFiles/Trees.dir/main.cpp.o: /Users/petrascheuer/Desktop/Trees/main.cpp
CMakeFiles/Trees.dir/main.cpp.o: CMakeFiles/Trees.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/petrascheuer/Desktop/Trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Trees.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trees.dir/main.cpp.o -MF CMakeFiles/Trees.dir/main.cpp.o.d -o CMakeFiles/Trees.dir/main.cpp.o -c /Users/petrascheuer/Desktop/Trees/main.cpp

CMakeFiles/Trees.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Trees.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petrascheuer/Desktop/Trees/main.cpp > CMakeFiles/Trees.dir/main.cpp.i

CMakeFiles/Trees.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Trees.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petrascheuer/Desktop/Trees/main.cpp -o CMakeFiles/Trees.dir/main.cpp.s

CMakeFiles/Trees.dir/AVLTree.cpp.o: CMakeFiles/Trees.dir/flags.make
CMakeFiles/Trees.dir/AVLTree.cpp.o: /Users/petrascheuer/Desktop/Trees/AVLTree.cpp
CMakeFiles/Trees.dir/AVLTree.cpp.o: CMakeFiles/Trees.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/petrascheuer/Desktop/Trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Trees.dir/AVLTree.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trees.dir/AVLTree.cpp.o -MF CMakeFiles/Trees.dir/AVLTree.cpp.o.d -o CMakeFiles/Trees.dir/AVLTree.cpp.o -c /Users/petrascheuer/Desktop/Trees/AVLTree.cpp

CMakeFiles/Trees.dir/AVLTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Trees.dir/AVLTree.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petrascheuer/Desktop/Trees/AVLTree.cpp > CMakeFiles/Trees.dir/AVLTree.cpp.i

CMakeFiles/Trees.dir/AVLTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Trees.dir/AVLTree.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petrascheuer/Desktop/Trees/AVLTree.cpp -o CMakeFiles/Trees.dir/AVLTree.cpp.s

CMakeFiles/Trees.dir/AVLTreeNode.cpp.o: CMakeFiles/Trees.dir/flags.make
CMakeFiles/Trees.dir/AVLTreeNode.cpp.o: /Users/petrascheuer/Desktop/Trees/AVLTreeNode.cpp
CMakeFiles/Trees.dir/AVLTreeNode.cpp.o: CMakeFiles/Trees.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/petrascheuer/Desktop/Trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Trees.dir/AVLTreeNode.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trees.dir/AVLTreeNode.cpp.o -MF CMakeFiles/Trees.dir/AVLTreeNode.cpp.o.d -o CMakeFiles/Trees.dir/AVLTreeNode.cpp.o -c /Users/petrascheuer/Desktop/Trees/AVLTreeNode.cpp

CMakeFiles/Trees.dir/AVLTreeNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Trees.dir/AVLTreeNode.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petrascheuer/Desktop/Trees/AVLTreeNode.cpp > CMakeFiles/Trees.dir/AVLTreeNode.cpp.i

CMakeFiles/Trees.dir/AVLTreeNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Trees.dir/AVLTreeNode.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petrascheuer/Desktop/Trees/AVLTreeNode.cpp -o CMakeFiles/Trees.dir/AVLTreeNode.cpp.s

CMakeFiles/Trees.dir/Programme.cpp.o: CMakeFiles/Trees.dir/flags.make
CMakeFiles/Trees.dir/Programme.cpp.o: /Users/petrascheuer/Desktop/Trees/Programme.cpp
CMakeFiles/Trees.dir/Programme.cpp.o: CMakeFiles/Trees.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/petrascheuer/Desktop/Trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Trees.dir/Programme.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trees.dir/Programme.cpp.o -MF CMakeFiles/Trees.dir/Programme.cpp.o.d -o CMakeFiles/Trees.dir/Programme.cpp.o -c /Users/petrascheuer/Desktop/Trees/Programme.cpp

CMakeFiles/Trees.dir/Programme.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Trees.dir/Programme.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petrascheuer/Desktop/Trees/Programme.cpp > CMakeFiles/Trees.dir/Programme.cpp.i

CMakeFiles/Trees.dir/Programme.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Trees.dir/Programme.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petrascheuer/Desktop/Trees/Programme.cpp -o CMakeFiles/Trees.dir/Programme.cpp.s

CMakeFiles/Trees.dir/Testing.cpp.o: CMakeFiles/Trees.dir/flags.make
CMakeFiles/Trees.dir/Testing.cpp.o: /Users/petrascheuer/Desktop/Trees/Testing.cpp
CMakeFiles/Trees.dir/Testing.cpp.o: CMakeFiles/Trees.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/petrascheuer/Desktop/Trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Trees.dir/Testing.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Trees.dir/Testing.cpp.o -MF CMakeFiles/Trees.dir/Testing.cpp.o.d -o CMakeFiles/Trees.dir/Testing.cpp.o -c /Users/petrascheuer/Desktop/Trees/Testing.cpp

CMakeFiles/Trees.dir/Testing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Trees.dir/Testing.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petrascheuer/Desktop/Trees/Testing.cpp > CMakeFiles/Trees.dir/Testing.cpp.i

CMakeFiles/Trees.dir/Testing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Trees.dir/Testing.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petrascheuer/Desktop/Trees/Testing.cpp -o CMakeFiles/Trees.dir/Testing.cpp.s

# Object files for target Trees
Trees_OBJECTS = \
"CMakeFiles/Trees.dir/main.cpp.o" \
"CMakeFiles/Trees.dir/AVLTree.cpp.o" \
"CMakeFiles/Trees.dir/AVLTreeNode.cpp.o" \
"CMakeFiles/Trees.dir/Programme.cpp.o" \
"CMakeFiles/Trees.dir/Testing.cpp.o"

# External object files for target Trees
Trees_EXTERNAL_OBJECTS =

Trees: CMakeFiles/Trees.dir/main.cpp.o
Trees: CMakeFiles/Trees.dir/AVLTree.cpp.o
Trees: CMakeFiles/Trees.dir/AVLTreeNode.cpp.o
Trees: CMakeFiles/Trees.dir/Programme.cpp.o
Trees: CMakeFiles/Trees.dir/Testing.cpp.o
Trees: CMakeFiles/Trees.dir/build.make
Trees: CMakeFiles/Trees.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/petrascheuer/Desktop/Trees/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Trees"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Trees.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Trees.dir/build: Trees
.PHONY : CMakeFiles/Trees.dir/build

CMakeFiles/Trees.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Trees.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Trees.dir/clean

CMakeFiles/Trees.dir/depend:
	cd /Users/petrascheuer/Desktop/Trees/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/petrascheuer/Desktop/Trees /Users/petrascheuer/Desktop/Trees /Users/petrascheuer/Desktop/Trees/cmake-build-debug /Users/petrascheuer/Desktop/Trees/cmake-build-debug /Users/petrascheuer/Desktop/Trees/cmake-build-debug/CMakeFiles/Trees.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Trees.dir/depend
