# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/storres/Documents/Info1/2016/01.11.2016

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/createTextInput.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/createTextInput.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/createTextInput.dir/flags.make

CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o: CMakeFiles/createTextInput.dir/flags.make
CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o: ../CrearCampoDeTexto/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o   -c /Users/storres/Documents/Info1/2016/01.11.2016/CrearCampoDeTexto/main.c

CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/storres/Documents/Info1/2016/01.11.2016/CrearCampoDeTexto/main.c > CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.i

CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/storres/Documents/Info1/2016/01.11.2016/CrearCampoDeTexto/main.c -o CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.s

CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o.requires:

.PHONY : CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o.requires

CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o.provides: CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o.requires
	$(MAKE) -f CMakeFiles/createTextInput.dir/build.make CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o.provides.build
.PHONY : CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o.provides

CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o.provides.build: CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o


# Object files for target createTextInput
createTextInput_OBJECTS = \
"CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o"

# External object files for target createTextInput
createTextInput_EXTERNAL_OBJECTS =

createTextInput: CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o
createTextInput: CMakeFiles/createTextInput.dir/build.make
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_calib3d.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_calib3d.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_calib3d.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_contrib.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_contrib.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_contrib.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_core.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_core.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_core.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_features2d.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_features2d.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_features2d.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_flann.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_flann.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_flann.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_gpu.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_gpu.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_gpu.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_highgui.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_highgui.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_highgui.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_imgproc.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_imgproc.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_imgproc.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_legacy.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_legacy.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_legacy.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ml.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ml.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ml.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_nonfree.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_nonfree.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_nonfree.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_objdetect.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_objdetect.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_objdetect.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ocl.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ocl.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ocl.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_photo.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_photo.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_photo.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_stitching.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_stitching.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_stitching.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_superres.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_superres.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_superres.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_video.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_video.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_video.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_videostab.2.4.13.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_videostab.2.4.dylib
createTextInput: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_videostab.dylib
createTextInput: CMakeFiles/createTextInput.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable createTextInput"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/createTextInput.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/createTextInput.dir/build: createTextInput

.PHONY : CMakeFiles/createTextInput.dir/build

CMakeFiles/createTextInput.dir/requires: CMakeFiles/createTextInput.dir/CrearCampoDeTexto/main.c.o.requires

.PHONY : CMakeFiles/createTextInput.dir/requires

CMakeFiles/createTextInput.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/createTextInput.dir/cmake_clean.cmake
.PHONY : CMakeFiles/createTextInput.dir/clean

CMakeFiles/createTextInput.dir/depend:
	cd /Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/storres/Documents/Info1/2016/01.11.2016 /Users/storres/Documents/Info1/2016/01.11.2016 /Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug /Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug /Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug/CMakeFiles/createTextInput.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/createTextInput.dir/depend

