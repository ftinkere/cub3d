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
CMAKE_COMMAND = /home/ftinkere/Progs/clion-2020.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ftinkere/Progs/clion-2020.3.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ftinkere/Prs/cub3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ftinkere/Prs/cub3d/cmake-build-debug

# Utility rule file for libft.

# Include the progress variables for this target.
include CMakeFiles/libft.dir/progress.make

CMakeFiles/libft:
	cd /home/ftinkere/Prs/cub3d/libft && make all

libft: CMakeFiles/libft
libft: CMakeFiles/libft.dir/build.make

.PHONY : libft

# Rule to build all files generated by this target.
CMakeFiles/libft.dir/build: libft

.PHONY : CMakeFiles/libft.dir/build

CMakeFiles/libft.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libft.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libft.dir/clean

CMakeFiles/libft.dir/depend:
	cd /home/ftinkere/Prs/cub3d/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ftinkere/Prs/cub3d /home/ftinkere/Prs/cub3d /home/ftinkere/Prs/cub3d/cmake-build-debug /home/ftinkere/Prs/cub3d/cmake-build-debug /home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles/libft.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libft.dir/depend

