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
CMAKE_COMMAND = "/Applications/CMake 2.8-10.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-10.app/Contents/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-10.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans

# Include any dependencies generated for this target.
include CMakeFiles/kmeans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kmeans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kmeans.dir/flags.make

CMakeFiles/kmeans.dir/kmeans_main.o: CMakeFiles/kmeans.dir/flags.make
CMakeFiles/kmeans.dir/kmeans_main.o: kmeans_main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kmeans.dir/kmeans_main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kmeans.dir/kmeans_main.o -c /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans/kmeans_main.cpp

CMakeFiles/kmeans.dir/kmeans_main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kmeans.dir/kmeans_main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans/kmeans_main.cpp > CMakeFiles/kmeans.dir/kmeans_main.i

CMakeFiles/kmeans.dir/kmeans_main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kmeans.dir/kmeans_main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans/kmeans_main.cpp -o CMakeFiles/kmeans.dir/kmeans_main.s

CMakeFiles/kmeans.dir/kmeans_main.o.requires:
.PHONY : CMakeFiles/kmeans.dir/kmeans_main.o.requires

CMakeFiles/kmeans.dir/kmeans_main.o.provides: CMakeFiles/kmeans.dir/kmeans_main.o.requires
	$(MAKE) -f CMakeFiles/kmeans.dir/build.make CMakeFiles/kmeans.dir/kmeans_main.o.provides.build
.PHONY : CMakeFiles/kmeans.dir/kmeans_main.o.provides

CMakeFiles/kmeans.dir/kmeans_main.o.provides.build: CMakeFiles/kmeans.dir/kmeans_main.o

# Object files for target kmeans
kmeans_OBJECTS = \
"CMakeFiles/kmeans.dir/kmeans_main.o"

# External object files for target kmeans
kmeans_EXTERNAL_OBJECTS =

kmeans: CMakeFiles/kmeans.dir/kmeans_main.o
kmeans: CMakeFiles/kmeans.dir/build.make
kmeans: CMakeFiles/kmeans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable kmeans"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kmeans.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kmeans.dir/build: kmeans
.PHONY : CMakeFiles/kmeans.dir/build

CMakeFiles/kmeans.dir/requires: CMakeFiles/kmeans.dir/kmeans_main.o.requires
.PHONY : CMakeFiles/kmeans.dir/requires

CMakeFiles/kmeans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kmeans.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kmeans.dir/clean

CMakeFiles/kmeans.dir/depend:
	cd /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans /Users/paulfrandsen/XCODE_PROJECTS/DAAD_project/mlpack-1.0.8/src/mlpack/methods/kmeans/CMakeFiles/kmeans.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kmeans.dir/depend

