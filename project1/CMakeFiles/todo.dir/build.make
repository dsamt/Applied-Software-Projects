# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /vagrant

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /vagrant

# Include any dependencies generated for this target.
include CMakeFiles/todo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/todo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/todo.dir/flags.make

CMakeFiles/todo.dir/todo.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/todo.cpp.o: todo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/todo.dir/todo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/todo.cpp.o -c /vagrant/todo.cpp

CMakeFiles/todo.dir/todo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/todo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /vagrant/todo.cpp > CMakeFiles/todo.dir/todo.cpp.i

CMakeFiles/todo.dir/todo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/todo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /vagrant/todo.cpp -o CMakeFiles/todo.dir/todo.cpp.s

CMakeFiles/todo.dir/todo.cpp.o.requires:

.PHONY : CMakeFiles/todo.dir/todo.cpp.o.requires

CMakeFiles/todo.dir/todo.cpp.o.provides: CMakeFiles/todo.dir/todo.cpp.o.requires
	$(MAKE) -f CMakeFiles/todo.dir/build.make CMakeFiles/todo.dir/todo.cpp.o.provides.build
.PHONY : CMakeFiles/todo.dir/todo.cpp.o.provides

CMakeFiles/todo.dir/todo.cpp.o.provides.build: CMakeFiles/todo.dir/todo.cpp.o


# Object files for target todo
todo_OBJECTS = \
"CMakeFiles/todo.dir/todo.cpp.o"

# External object files for target todo
todo_EXTERNAL_OBJECTS =

todo: CMakeFiles/todo.dir/todo.cpp.o
todo: CMakeFiles/todo.dir/build.make
todo: CMakeFiles/todo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/vagrant/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable todo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/todo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/todo.dir/build: todo

.PHONY : CMakeFiles/todo.dir/build

CMakeFiles/todo.dir/requires: CMakeFiles/todo.dir/todo.cpp.o.requires

.PHONY : CMakeFiles/todo.dir/requires

CMakeFiles/todo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/todo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/todo.dir/clean

CMakeFiles/todo.dir/depend:
	cd /vagrant && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /vagrant /vagrant /vagrant /vagrant /vagrant/CMakeFiles/todo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/todo.dir/depend

