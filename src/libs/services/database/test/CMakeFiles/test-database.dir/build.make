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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shree/Downloads/lms-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shree/Downloads/lms-master

# Include any dependencies generated for this target.
include src/libs/services/database/test/CMakeFiles/test-database.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.make

# Include the progress variables for this target.
include src/libs/services/database/test/CMakeFiles/test-database.dir/progress.make

# Include the compile flags for this target's objects.
include src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make

src/libs/services/database/test/CMakeFiles/test-database.dir/Artist.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/Artist.cpp.o: src/libs/services/database/test/Artist.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/Artist.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/Artist.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/Artist.cpp.o -MF CMakeFiles/test-database.dir/Artist.cpp.o.d -o CMakeFiles/test-database.dir/Artist.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/Artist.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/Artist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/Artist.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/Artist.cpp > CMakeFiles/test-database.dir/Artist.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/Artist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/Artist.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/Artist.cpp -o CMakeFiles/test-database.dir/Artist.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/Cluster.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/Cluster.cpp.o: src/libs/services/database/test/Cluster.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/Cluster.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/Cluster.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/Cluster.cpp.o -MF CMakeFiles/test-database.dir/Cluster.cpp.o.d -o CMakeFiles/test-database.dir/Cluster.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/Cluster.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/Cluster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/Cluster.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/Cluster.cpp > CMakeFiles/test-database.dir/Cluster.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/Cluster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/Cluster.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/Cluster.cpp -o CMakeFiles/test-database.dir/Cluster.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/Common.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/Common.cpp.o: src/libs/services/database/test/Common.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/Common.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/Common.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/Common.cpp.o -MF CMakeFiles/test-database.dir/Common.cpp.o.d -o CMakeFiles/test-database.dir/Common.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/Common.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/Common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/Common.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/Common.cpp > CMakeFiles/test-database.dir/Common.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/Common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/Common.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/Common.cpp -o CMakeFiles/test-database.dir/Common.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/DatabaseTest.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/DatabaseTest.cpp.o: src/libs/services/database/test/DatabaseTest.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/DatabaseTest.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/DatabaseTest.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/DatabaseTest.cpp.o -MF CMakeFiles/test-database.dir/DatabaseTest.cpp.o.d -o CMakeFiles/test-database.dir/DatabaseTest.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/DatabaseTest.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/DatabaseTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/DatabaseTest.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/DatabaseTest.cpp > CMakeFiles/test-database.dir/DatabaseTest.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/DatabaseTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/DatabaseTest.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/DatabaseTest.cpp -o CMakeFiles/test-database.dir/DatabaseTest.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/Listen.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/Listen.cpp.o: src/libs/services/database/test/Listen.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/Listen.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/Listen.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/Listen.cpp.o -MF CMakeFiles/test-database.dir/Listen.cpp.o.d -o CMakeFiles/test-database.dir/Listen.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/Listen.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/Listen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/Listen.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/Listen.cpp > CMakeFiles/test-database.dir/Listen.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/Listen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/Listen.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/Listen.cpp -o CMakeFiles/test-database.dir/Listen.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/Release.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/Release.cpp.o: src/libs/services/database/test/Release.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/Release.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/Release.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/Release.cpp.o -MF CMakeFiles/test-database.dir/Release.cpp.o.d -o CMakeFiles/test-database.dir/Release.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/Release.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/Release.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/Release.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/Release.cpp > CMakeFiles/test-database.dir/Release.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/Release.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/Release.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/Release.cpp -o CMakeFiles/test-database.dir/Release.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/StarredArtist.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/StarredArtist.cpp.o: src/libs/services/database/test/StarredArtist.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/StarredArtist.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/StarredArtist.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/StarredArtist.cpp.o -MF CMakeFiles/test-database.dir/StarredArtist.cpp.o.d -o CMakeFiles/test-database.dir/StarredArtist.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/StarredArtist.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/StarredArtist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/StarredArtist.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/StarredArtist.cpp > CMakeFiles/test-database.dir/StarredArtist.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/StarredArtist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/StarredArtist.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/StarredArtist.cpp -o CMakeFiles/test-database.dir/StarredArtist.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/StarredRelease.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/StarredRelease.cpp.o: src/libs/services/database/test/StarredRelease.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/StarredRelease.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/StarredRelease.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/StarredRelease.cpp.o -MF CMakeFiles/test-database.dir/StarredRelease.cpp.o.d -o CMakeFiles/test-database.dir/StarredRelease.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/StarredRelease.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/StarredRelease.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/StarredRelease.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/StarredRelease.cpp > CMakeFiles/test-database.dir/StarredRelease.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/StarredRelease.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/StarredRelease.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/StarredRelease.cpp -o CMakeFiles/test-database.dir/StarredRelease.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/StarredTrack.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/StarredTrack.cpp.o: src/libs/services/database/test/StarredTrack.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/StarredTrack.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/StarredTrack.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/StarredTrack.cpp.o -MF CMakeFiles/test-database.dir/StarredTrack.cpp.o.d -o CMakeFiles/test-database.dir/StarredTrack.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/StarredTrack.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/StarredTrack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/StarredTrack.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/StarredTrack.cpp > CMakeFiles/test-database.dir/StarredTrack.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/StarredTrack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/StarredTrack.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/StarredTrack.cpp -o CMakeFiles/test-database.dir/StarredTrack.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/Track.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/Track.cpp.o: src/libs/services/database/test/Track.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/Track.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/Track.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/Track.cpp.o -MF CMakeFiles/test-database.dir/Track.cpp.o.d -o CMakeFiles/test-database.dir/Track.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/Track.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/Track.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/Track.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/Track.cpp > CMakeFiles/test-database.dir/Track.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/Track.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/Track.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/Track.cpp -o CMakeFiles/test-database.dir/Track.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/TrackBookmark.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/TrackBookmark.cpp.o: src/libs/services/database/test/TrackBookmark.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/TrackBookmark.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/TrackBookmark.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/TrackBookmark.cpp.o -MF CMakeFiles/test-database.dir/TrackBookmark.cpp.o.d -o CMakeFiles/test-database.dir/TrackBookmark.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/TrackBookmark.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/TrackBookmark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/TrackBookmark.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/TrackBookmark.cpp > CMakeFiles/test-database.dir/TrackBookmark.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/TrackBookmark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/TrackBookmark.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/TrackBookmark.cpp -o CMakeFiles/test-database.dir/TrackBookmark.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/TrackFeatures.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/TrackFeatures.cpp.o: src/libs/services/database/test/TrackFeatures.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/TrackFeatures.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/TrackFeatures.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/TrackFeatures.cpp.o -MF CMakeFiles/test-database.dir/TrackFeatures.cpp.o.d -o CMakeFiles/test-database.dir/TrackFeatures.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/TrackFeatures.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/TrackFeatures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/TrackFeatures.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/TrackFeatures.cpp > CMakeFiles/test-database.dir/TrackFeatures.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/TrackFeatures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/TrackFeatures.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/TrackFeatures.cpp -o CMakeFiles/test-database.dir/TrackFeatures.cpp.s

src/libs/services/database/test/CMakeFiles/test-database.dir/TrackList.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/flags.make
src/libs/services/database/test/CMakeFiles/test-database.dir/TrackList.cpp.o: src/libs/services/database/test/TrackList.cpp
src/libs/services/database/test/CMakeFiles/test-database.dir/TrackList.cpp.o: src/libs/services/database/test/CMakeFiles/test-database.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/libs/services/database/test/CMakeFiles/test-database.dir/TrackList.cpp.o"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/database/test/CMakeFiles/test-database.dir/TrackList.cpp.o -MF CMakeFiles/test-database.dir/TrackList.cpp.o.d -o CMakeFiles/test-database.dir/TrackList.cpp.o -c /Users/shree/Downloads/lms-master/src/libs/services/database/test/TrackList.cpp

src/libs/services/database/test/CMakeFiles/test-database.dir/TrackList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-database.dir/TrackList.cpp.i"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/lms-master/src/libs/services/database/test/TrackList.cpp > CMakeFiles/test-database.dir/TrackList.cpp.i

src/libs/services/database/test/CMakeFiles/test-database.dir/TrackList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-database.dir/TrackList.cpp.s"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/lms-master/src/libs/services/database/test/TrackList.cpp -o CMakeFiles/test-database.dir/TrackList.cpp.s

# Object files for target test-database
test__database_OBJECTS = \
"CMakeFiles/test-database.dir/Artist.cpp.o" \
"CMakeFiles/test-database.dir/Cluster.cpp.o" \
"CMakeFiles/test-database.dir/Common.cpp.o" \
"CMakeFiles/test-database.dir/DatabaseTest.cpp.o" \
"CMakeFiles/test-database.dir/Listen.cpp.o" \
"CMakeFiles/test-database.dir/Release.cpp.o" \
"CMakeFiles/test-database.dir/StarredArtist.cpp.o" \
"CMakeFiles/test-database.dir/StarredRelease.cpp.o" \
"CMakeFiles/test-database.dir/StarredTrack.cpp.o" \
"CMakeFiles/test-database.dir/Track.cpp.o" \
"CMakeFiles/test-database.dir/TrackBookmark.cpp.o" \
"CMakeFiles/test-database.dir/TrackFeatures.cpp.o" \
"CMakeFiles/test-database.dir/TrackList.cpp.o"

# External object files for target test-database
test__database_EXTERNAL_OBJECTS =

src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/Artist.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/Cluster.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/Common.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/DatabaseTest.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/Listen.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/Release.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/StarredArtist.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/StarredRelease.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/StarredTrack.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/Track.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/TrackBookmark.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/TrackFeatures.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/TrackList.cpp.o
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/build.make
src/libs/services/database/test/test-database: src/libs/services/database/liblmsdatabase.dylib
src/libs/services/database/test/test-database: src/libs/utils/liblmsutils.dylib
src/libs/services/database/test/test-database: /opt/homebrew/lib/libboost_system-mt.dylib
src/libs/services/database/test/test-database: /usr/local/lib/libwt.4.10.1.dylib
src/libs/services/database/test/test-database: /opt/homebrew/lib/libboost_thread-mt.dylib
src/libs/services/database/test/test-database: /opt/homebrew/lib/libboost_filesystem-mt.dylib
src/libs/services/database/test/test-database: /opt/homebrew/lib/libboost_atomic-mt.dylib
src/libs/services/database/test/test-database: /usr/local/lib/libwtdbo.4.10.1.dylib
src/libs/services/database/test/test-database: /opt/homebrew/lib/libgtest.a
src/libs/services/database/test/test-database: src/libs/services/database/test/CMakeFiles/test-database.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/shree/Downloads/lms-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable test-database"
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-database.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -D TEST_TARGET=test-database -D TEST_EXECUTABLE=/Users/shree/Downloads/lms-master/src/libs/services/database/test/test-database -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/shree/Downloads/lms-master/src/libs/services/database/test -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test-database_TESTS -D CTEST_FILE=/Users/shree/Downloads/lms-master/src/libs/services/database/test/test-database[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/Cellar/cmake/3.27.7/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
src/libs/services/database/test/CMakeFiles/test-database.dir/build: src/libs/services/database/test/test-database
.PHONY : src/libs/services/database/test/CMakeFiles/test-database.dir/build

src/libs/services/database/test/CMakeFiles/test-database.dir/clean:
	cd /Users/shree/Downloads/lms-master/src/libs/services/database/test && $(CMAKE_COMMAND) -P CMakeFiles/test-database.dir/cmake_clean.cmake
.PHONY : src/libs/services/database/test/CMakeFiles/test-database.dir/clean

src/libs/services/database/test/CMakeFiles/test-database.dir/depend:
	cd /Users/shree/Downloads/lms-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shree/Downloads/lms-master /Users/shree/Downloads/lms-master/src/libs/services/database/test /Users/shree/Downloads/lms-master /Users/shree/Downloads/lms-master/src/libs/services/database/test /Users/shree/Downloads/lms-master/src/libs/services/database/test/CMakeFiles/test-database.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/libs/services/database/test/CMakeFiles/test-database.dir/depend
