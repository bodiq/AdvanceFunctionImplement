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
CMAKE_COMMAND = "/Applications/CLion 2.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Applications/CLion 2.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bodya/Desktop/С++/AdvancedC++/Section8_55

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bodya/Desktop/С++/AdvancedC++/Section8_55/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Section8_55.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Section8_55.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Section8_55.dir/flags.make

CMakeFiles/Section8_55.dir/main.cpp.o: CMakeFiles/Section8_55.dir/flags.make
CMakeFiles/Section8_55.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bodya/Desktop/С++/AdvancedC++/Section8_55/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Section8_55.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Section8_55.dir/main.cpp.o -c /Users/bodya/Desktop/С++/AdvancedC++/Section8_55/main.cpp

CMakeFiles/Section8_55.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Section8_55.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bodya/Desktop/С++/AdvancedC++/Section8_55/main.cpp > CMakeFiles/Section8_55.dir/main.cpp.i

CMakeFiles/Section8_55.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Section8_55.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bodya/Desktop/С++/AdvancedC++/Section8_55/main.cpp -o CMakeFiles/Section8_55.dir/main.cpp.s

# Object files for target Section8_55
Section8_55_OBJECTS = \
"CMakeFiles/Section8_55.dir/main.cpp.o"

# External object files for target Section8_55
Section8_55_EXTERNAL_OBJECTS =

Section8_55: CMakeFiles/Section8_55.dir/main.cpp.o
Section8_55: CMakeFiles/Section8_55.dir/build.make
Section8_55: CMakeFiles/Section8_55.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bodya/Desktop/С++/AdvancedC++/Section8_55/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Section8_55"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Section8_55.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Section8_55.dir/build: Section8_55

.PHONY : CMakeFiles/Section8_55.dir/build

CMakeFiles/Section8_55.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Section8_55.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Section8_55.dir/clean

CMakeFiles/Section8_55.dir/depend:
	cd /Users/bodya/Desktop/С++/AdvancedC++/Section8_55/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bodya/Desktop/С++/AdvancedC++/Section8_55 /Users/bodya/Desktop/С++/AdvancedC++/Section8_55 /Users/bodya/Desktop/С++/AdvancedC++/Section8_55/cmake-build-debug /Users/bodya/Desktop/С++/AdvancedC++/Section8_55/cmake-build-debug /Users/bodya/Desktop/С++/AdvancedC++/Section8_55/cmake-build-debug/CMakeFiles/Section8_55.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Section8_55.dir/depend

