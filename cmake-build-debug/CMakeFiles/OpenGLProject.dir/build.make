# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenGLProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenGLProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGLProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGLProject.dir/flags.make

CMakeFiles/OpenGLProject.dir/main.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/main.cpp.o: ../main.cpp
CMakeFiles/OpenGLProject.dir/main.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGLProject.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/main.cpp.o -MF CMakeFiles/OpenGLProject.dir/main.cpp.o.d -o CMakeFiles/OpenGLProject.dir/main.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/main.cpp

CMakeFiles/OpenGLProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/main.cpp > CMakeFiles/OpenGLProject.dir/main.cpp.i

CMakeFiles/OpenGLProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/main.cpp -o CMakeFiles/OpenGLProject.dir/main.cpp.s

CMakeFiles/OpenGLProject.dir/src/Application.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/Application.cpp.o: ../src/Application.cpp
CMakeFiles/OpenGLProject.dir/src/Application.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGLProject.dir/src/Application.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/Application.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/Application.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/Application.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Application.cpp

CMakeFiles/OpenGLProject.dir/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/Application.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Application.cpp > CMakeFiles/OpenGLProject.dir/src/Application.cpp.i

CMakeFiles/OpenGLProject.dir/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/Application.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Application.cpp -o CMakeFiles/OpenGLProject.dir/src/Application.cpp.s

CMakeFiles/OpenGLProject.dir/src/Window.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/Window.cpp.o: ../src/Window.cpp
CMakeFiles/OpenGLProject.dir/src/Window.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGLProject.dir/src/Window.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/Window.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/Window.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/Window.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Window.cpp

CMakeFiles/OpenGLProject.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/Window.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Window.cpp > CMakeFiles/OpenGLProject.dir/src/Window.cpp.i

CMakeFiles/OpenGLProject.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/Window.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Window.cpp -o CMakeFiles/OpenGLProject.dir/src/Window.cpp.s

CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.o: ../src/Renderer.cpp
CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Renderer.cpp

CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Renderer.cpp > CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.i

CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Renderer.cpp -o CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.s

CMakeFiles/OpenGLProject.dir/src/Shader.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/Shader.cpp.o: ../src/Shader.cpp
CMakeFiles/OpenGLProject.dir/src/Shader.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OpenGLProject.dir/src/Shader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/Shader.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/Shader.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/Shader.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Shader.cpp

CMakeFiles/OpenGLProject.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/Shader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Shader.cpp > CMakeFiles/OpenGLProject.dir/src/Shader.cpp.i

CMakeFiles/OpenGLProject.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/Shader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Shader.cpp -o CMakeFiles/OpenGLProject.dir/src/Shader.cpp.s

CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.o: ../src/FileParser.cpp
CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/FileParser.cpp

CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/FileParser.cpp > CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.i

CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/FileParser.cpp -o CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.s

CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.o: ../src/VertexBuffer.cpp
CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/VertexBuffer.cpp

CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/VertexBuffer.cpp > CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.i

CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/VertexBuffer.cpp -o CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.s

CMakeFiles/OpenGLProject.dir/src/GObject.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/GObject.cpp.o: ../src/GObject.cpp
CMakeFiles/OpenGLProject.dir/src/GObject.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/OpenGLProject.dir/src/GObject.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/GObject.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/GObject.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/GObject.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/GObject.cpp

CMakeFiles/OpenGLProject.dir/src/GObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/GObject.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/GObject.cpp > CMakeFiles/OpenGLProject.dir/src/GObject.cpp.i

CMakeFiles/OpenGLProject.dir/src/GObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/GObject.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/GObject.cpp -o CMakeFiles/OpenGLProject.dir/src/GObject.cpp.s

CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.o: ../src/GObjectFactory.cpp
CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/GObjectFactory.cpp

CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/GObjectFactory.cpp > CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.i

CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/GObjectFactory.cpp -o CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.s

CMakeFiles/OpenGLProject.dir/src/Texture.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/Texture.cpp.o: ../src/Texture.cpp
CMakeFiles/OpenGLProject.dir/src/Texture.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/OpenGLProject.dir/src/Texture.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/Texture.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/Texture.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/Texture.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Texture.cpp

CMakeFiles/OpenGLProject.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/Texture.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Texture.cpp > CMakeFiles/OpenGLProject.dir/src/Texture.cpp.i

CMakeFiles/OpenGLProject.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/Texture.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Texture.cpp -o CMakeFiles/OpenGLProject.dir/src/Texture.cpp.s

CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.o: ../include/vendor/stb_image.cpp
CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.o -MF CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.o.d -o CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/include/vendor/stb_image.cpp

CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/include/vendor/stb_image.cpp > CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.i

CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/include/vendor/stb_image.cpp -o CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.s

CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.o: ../src/control/Controller.cpp
CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/Controller.cpp

CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/Controller.cpp > CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.i

CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/Controller.cpp -o CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.s

CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.o: ../src/control/FuncModule.cpp
CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/FuncModule.cpp

CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/FuncModule.cpp > CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.i

CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/FuncModule.cpp -o CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.s

CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.o: ../src/control/modules/ManualMov.cpp
CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/modules/ManualMov.cpp

CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/modules/ManualMov.cpp > CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.i

CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/modules/ManualMov.cpp -o CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.s

CMakeFiles/OpenGLProject.dir/src/Camera.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/Camera.cpp.o: ../src/Camera.cpp
CMakeFiles/OpenGLProject.dir/src/Camera.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/OpenGLProject.dir/src/Camera.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/Camera.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/Camera.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/Camera.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Camera.cpp

CMakeFiles/OpenGLProject.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/Camera.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Camera.cpp > CMakeFiles/OpenGLProject.dir/src/Camera.cpp.i

CMakeFiles/OpenGLProject.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/Camera.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/Camera.cpp -o CMakeFiles/OpenGLProject.dir/src/Camera.cpp.s

CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.o: CMakeFiles/OpenGLProject.dir/flags.make
CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.o: ../src/control/modules/CameraMov.cpp
CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.o: CMakeFiles/OpenGLProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.o -MF CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.o.d -o CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.o -c /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/modules/CameraMov.cpp

CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/modules/CameraMov.cpp > CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.i

CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/src/control/modules/CameraMov.cpp -o CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.s

# Object files for target OpenGLProject
OpenGLProject_OBJECTS = \
"CMakeFiles/OpenGLProject.dir/main.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/Application.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/Window.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/Shader.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/GObject.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/Texture.cpp.o" \
"CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/Camera.cpp.o" \
"CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.o"

# External object files for target OpenGLProject
OpenGLProject_EXTERNAL_OBJECTS =

OpenGLProject: CMakeFiles/OpenGLProject.dir/main.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/Application.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/Window.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/Renderer.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/Shader.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/FileParser.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/VertexBuffer.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/GObject.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/GObjectFactory.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/Texture.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/include/vendor/stb_image.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/control/Controller.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/control/FuncModule.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/control/modules/ManualMov.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/Camera.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/src/control/modules/CameraMov.cpp.o
OpenGLProject: CMakeFiles/OpenGLProject.dir/build.make
OpenGLProject: CMakeFiles/OpenGLProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable OpenGLProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGLProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGLProject.dir/build: OpenGLProject
.PHONY : CMakeFiles/OpenGLProject.dir/build

CMakeFiles/OpenGLProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGLProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGLProject.dir/clean

CMakeFiles/OpenGLProject.dir/depend:
	cd /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug /Users/matheusbellini/Desktop/USP/CompGraf/OpenGLProject/cmake-build-debug/CMakeFiles/OpenGLProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGLProject.dir/depend

