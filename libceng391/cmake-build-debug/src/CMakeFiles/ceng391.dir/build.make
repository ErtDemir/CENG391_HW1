# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Ertugrul Demir\Desktop\libceng391"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Ertugrul Demir\Desktop\libceng391\cmake-build-debug"

# Include any dependencies generated for this target.
include src/CMakeFiles/ceng391.dir/depend.make
# Include the progress variables for this target.
include src/CMakeFiles/ceng391.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ceng391.dir/flags.make

src/CMakeFiles/ceng391.dir/image.cpp.obj: src/CMakeFiles/ceng391.dir/flags.make
src/CMakeFiles/ceng391.dir/image.cpp.obj: src/CMakeFiles/ceng391.dir/includes_CXX.rsp
src/CMakeFiles/ceng391.dir/image.cpp.obj: ../src/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Ertugrul Demir\Desktop\libceng391\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ceng391.dir/image.cpp.obj"
	cd /d C:\Users\ERTUGR~1\Desktop\LIBCEN~1\CMAKE-~1\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ceng391.dir\image.cpp.obj -c "C:\Users\Ertugrul Demir\Desktop\libceng391\src\image.cpp"

src/CMakeFiles/ceng391.dir/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ceng391.dir/image.cpp.i"
	cd /d C:\Users\ERTUGR~1\Desktop\LIBCEN~1\CMAKE-~1\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Ertugrul Demir\Desktop\libceng391\src\image.cpp" > CMakeFiles\ceng391.dir\image.cpp.i

src/CMakeFiles/ceng391.dir/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ceng391.dir/image.cpp.s"
	cd /d C:\Users\ERTUGR~1\Desktop\LIBCEN~1\CMAKE-~1\src && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Ertugrul Demir\Desktop\libceng391\src\image.cpp" -o CMakeFiles\ceng391.dir\image.cpp.s

# Object files for target ceng391
ceng391_OBJECTS = \
"CMakeFiles/ceng391.dir/image.cpp.obj"

# External object files for target ceng391
ceng391_EXTERNAL_OBJECTS =

src/libceng391.a: src/CMakeFiles/ceng391.dir/image.cpp.obj
src/libceng391.a: src/CMakeFiles/ceng391.dir/build.make
src/libceng391.a: src/CMakeFiles/ceng391.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Ertugrul Demir\Desktop\libceng391\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libceng391.a"
	cd /d C:\Users\ERTUGR~1\Desktop\LIBCEN~1\CMAKE-~1\src && $(CMAKE_COMMAND) -P CMakeFiles\ceng391.dir\cmake_clean_target.cmake
	cd /d C:\Users\ERTUGR~1\Desktop\LIBCEN~1\CMAKE-~1\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ceng391.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ceng391.dir/build: src/libceng391.a
.PHONY : src/CMakeFiles/ceng391.dir/build

src/CMakeFiles/ceng391.dir/clean:
	cd /d C:\Users\ERTUGR~1\Desktop\LIBCEN~1\CMAKE-~1\src && $(CMAKE_COMMAND) -P CMakeFiles\ceng391.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/ceng391.dir/clean

src/CMakeFiles/ceng391.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Ertugrul Demir\Desktop\libceng391" "C:\Users\Ertugrul Demir\Desktop\libceng391\src" "C:\Users\Ertugrul Demir\Desktop\libceng391\cmake-build-debug" "C:\Users\Ertugrul Demir\Desktop\libceng391\cmake-build-debug\src" "C:\Users\Ertugrul Demir\Desktop\libceng391\cmake-build-debug\src\CMakeFiles\ceng391.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/ceng391.dir/depend

