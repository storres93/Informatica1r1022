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
include CMakeFiles/showImage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/showImage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/showImage.dir/flags.make

CMakeFiles/showImage.dir/MostrarImagen/main.c.o: CMakeFiles/showImage.dir/flags.make
CMakeFiles/showImage.dir/MostrarImagen/main.c.o: ../MostrarImagen/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/showImage.dir/MostrarImagen/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/showImage.dir/MostrarImagen/main.c.o   -c /Users/storres/Documents/Info1/2016/01.11.2016/MostrarImagen/main.c

CMakeFiles/showImage.dir/MostrarImagen/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/showImage.dir/MostrarImagen/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/storres/Documents/Info1/2016/01.11.2016/MostrarImagen/main.c > CMakeFiles/showImage.dir/MostrarImagen/main.c.i

CMakeFiles/showImage.dir/MostrarImagen/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/showImage.dir/MostrarImagen/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/storres/Documents/Info1/2016/01.11.2016/MostrarImagen/main.c -o CMakeFiles/showImage.dir/MostrarImagen/main.c.s

CMakeFiles/showImage.dir/MostrarImagen/main.c.o.requires:

.PHONY : CMakeFiles/showImage.dir/MostrarImagen/main.c.o.requires

CMakeFiles/showImage.dir/MostrarImagen/main.c.o.provides: CMakeFiles/showImage.dir/MostrarImagen/main.c.o.requires
	$(MAKE) -f CMakeFiles/showImage.dir/build.make CMakeFiles/showImage.dir/MostrarImagen/main.c.o.provides.build
.PHONY : CMakeFiles/showImage.dir/MostrarImagen/main.c.o.provides

CMakeFiles/showImage.dir/MostrarImagen/main.c.o.provides.build: CMakeFiles/showImage.dir/MostrarImagen/main.c.o


# Object files for target showImage
showImage_OBJECTS = \
"CMakeFiles/showImage.dir/MostrarImagen/main.c.o"

# External object files for target showImage
showImage_EXTERNAL_OBJECTS =

showImage: CMakeFiles/showImage.dir/MostrarImagen/main.c.o
showImage: CMakeFiles/showImage.dir/build.make
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_calib3d.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_calib3d.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_calib3d.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_contrib.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_contrib.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_contrib.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_core.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_core.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_core.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_features2d.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_features2d.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_features2d.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_flann.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_flann.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_flann.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_gpu.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_gpu.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_gpu.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_highgui.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_highgui.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_highgui.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_imgproc.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_imgproc.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_imgproc.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_legacy.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_legacy.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_legacy.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ml.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ml.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ml.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_nonfree.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_nonfree.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_nonfree.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_objdetect.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_objdetect.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_objdetect.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ocl.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ocl.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_ocl.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_photo.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_photo.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_photo.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_stitching.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_stitching.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_stitching.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_superres.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_superres.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_superres.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_video.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_video.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_video.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_videostab.2.4.13.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_videostab.2.4.dylib
showImage: /usr/local/Cellar/opencv/2.4.13.2/lib/libopencv_videostab.dylib
showImage: CMakeFiles/showImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable showImage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/showImage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/showImage.dir/build: showImage

.PHONY : CMakeFiles/showImage.dir/build

CMakeFiles/showImage.dir/requires: CMakeFiles/showImage.dir/MostrarImagen/main.c.o.requires

.PHONY : CMakeFiles/showImage.dir/requires

CMakeFiles/showImage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/showImage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/showImage.dir/clean

CMakeFiles/showImage.dir/depend:
	cd /Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/storres/Documents/Info1/2016/01.11.2016 /Users/storres/Documents/Info1/2016/01.11.2016 /Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug /Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug /Users/storres/Documents/Info1/2016/01.11.2016/cmake-build-debug/CMakeFiles/showImage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/showImage.dir/depend

