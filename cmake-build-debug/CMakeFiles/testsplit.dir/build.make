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

# Include any dependencies generated for this target.
include CMakeFiles/testsplit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testsplit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testsplit.dir/flags.make

CMakeFiles/testsplit.dir/libft/srcs/main.c.o: CMakeFiles/testsplit.dir/flags.make
CMakeFiles/testsplit.dir/libft/srcs/main.c.o: ../libft/srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/testsplit.dir/libft/srcs/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testsplit.dir/libft/srcs/main.c.o   -c /home/ftinkere/Prs/cub3d/libft/srcs/main.c

CMakeFiles/testsplit.dir/libft/srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testsplit.dir/libft/srcs/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ftinkere/Prs/cub3d/libft/srcs/main.c > CMakeFiles/testsplit.dir/libft/srcs/main.c.i

CMakeFiles/testsplit.dir/libft/srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testsplit.dir/libft/srcs/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ftinkere/Prs/cub3d/libft/srcs/main.c -o CMakeFiles/testsplit.dir/libft/srcs/main.c.s

CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.o: CMakeFiles/testsplit.dir/flags.make
CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.o: ../libft/srcs/ft_split.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.o   -c /home/ftinkere/Prs/cub3d/libft/srcs/ft_split.c

CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ftinkere/Prs/cub3d/libft/srcs/ft_split.c > CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.i

CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ftinkere/Prs/cub3d/libft/srcs/ft_split.c -o CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.s

CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.o: CMakeFiles/testsplit.dir/flags.make
CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.o: ../libft/srcs/ft_strchr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.o   -c /home/ftinkere/Prs/cub3d/libft/srcs/ft_strchr.c

CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ftinkere/Prs/cub3d/libft/srcs/ft_strchr.c > CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.i

CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ftinkere/Prs/cub3d/libft/srcs/ft_strchr.c -o CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.s

CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.o: CMakeFiles/testsplit.dir/flags.make
CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.o: ../libft/srcs/ft_strlen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.o   -c /home/ftinkere/Prs/cub3d/libft/srcs/ft_strlen.c

CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ftinkere/Prs/cub3d/libft/srcs/ft_strlen.c > CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.i

CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ftinkere/Prs/cub3d/libft/srcs/ft_strlen.c -o CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.s

CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.o: CMakeFiles/testsplit.dir/flags.make
CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.o: ../libft/srcs/ft_substr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.o   -c /home/ftinkere/Prs/cub3d/libft/srcs/ft_substr.c

CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ftinkere/Prs/cub3d/libft/srcs/ft_substr.c > CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.i

CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ftinkere/Prs/cub3d/libft/srcs/ft_substr.c -o CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.s

CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.o: CMakeFiles/testsplit.dir/flags.make
CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.o: ../libft/srcs/ft_memchr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.o   -c /home/ftinkere/Prs/cub3d/libft/srcs/ft_memchr.c

CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ftinkere/Prs/cub3d/libft/srcs/ft_memchr.c > CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.i

CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ftinkere/Prs/cub3d/libft/srcs/ft_memchr.c -o CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.s

CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.o: CMakeFiles/testsplit.dir/flags.make
CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.o: ../libft/srcs/ft_memcpy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.o   -c /home/ftinkere/Prs/cub3d/libft/srcs/ft_memcpy.c

CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ftinkere/Prs/cub3d/libft/srcs/ft_memcpy.c > CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.i

CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ftinkere/Prs/cub3d/libft/srcs/ft_memcpy.c -o CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.s

CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.o: CMakeFiles/testsplit.dir/flags.make
CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.o: ../libft/srcs/ft_memccpy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.o   -c /home/ftinkere/Prs/cub3d/libft/srcs/ft_memccpy.c

CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ftinkere/Prs/cub3d/libft/srcs/ft_memccpy.c > CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.i

CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ftinkere/Prs/cub3d/libft/srcs/ft_memccpy.c -o CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.s

# Object files for target testsplit
testsplit_OBJECTS = \
"CMakeFiles/testsplit.dir/libft/srcs/main.c.o" \
"CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.o" \
"CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.o" \
"CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.o" \
"CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.o" \
"CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.o" \
"CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.o" \
"CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.o"

# External object files for target testsplit
testsplit_EXTERNAL_OBJECTS =

testsplit: CMakeFiles/testsplit.dir/libft/srcs/main.c.o
testsplit: CMakeFiles/testsplit.dir/libft/srcs/ft_split.c.o
testsplit: CMakeFiles/testsplit.dir/libft/srcs/ft_strchr.c.o
testsplit: CMakeFiles/testsplit.dir/libft/srcs/ft_strlen.c.o
testsplit: CMakeFiles/testsplit.dir/libft/srcs/ft_substr.c.o
testsplit: CMakeFiles/testsplit.dir/libft/srcs/ft_memchr.c.o
testsplit: CMakeFiles/testsplit.dir/libft/srcs/ft_memcpy.c.o
testsplit: CMakeFiles/testsplit.dir/libft/srcs/ft_memccpy.c.o
testsplit: CMakeFiles/testsplit.dir/build.make
testsplit: CMakeFiles/testsplit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable testsplit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testsplit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testsplit.dir/build: testsplit

.PHONY : CMakeFiles/testsplit.dir/build

CMakeFiles/testsplit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testsplit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testsplit.dir/clean

CMakeFiles/testsplit.dir/depend:
	cd /home/ftinkere/Prs/cub3d/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ftinkere/Prs/cub3d /home/ftinkere/Prs/cub3d /home/ftinkere/Prs/cub3d/cmake-build-debug /home/ftinkere/Prs/cub3d/cmake-build-debug /home/ftinkere/Prs/cub3d/cmake-build-debug/CMakeFiles/testsplit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testsplit.dir/depend
