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
CMAKE_SOURCE_DIR = /Users/shree/Downloads/Music-Streaming-Service

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shree/Downloads/Music-Streaming-Service

# Include any dependencies generated for this target.
include src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.make

# Include the progress variables for this target.
include src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/progress.make

# Include the compile flags for this target's objects.
include src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.o: src/libs/services/recommendation/impl/clusters/ClustersEngine.cpp
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.o -MF CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.o.d -o CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/clusters/ClustersEngine.cpp

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/clusters/ClustersEngine.cpp > CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.i

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/clusters/ClustersEngine.cpp -o CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.s

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.o: src/libs/services/recommendation/impl/features/FeaturesEngineCache.cpp
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.o -MF CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.o.d -o CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/features/FeaturesEngineCache.cpp

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/features/FeaturesEngineCache.cpp > CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.i

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/features/FeaturesEngineCache.cpp -o CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.s

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.o: src/libs/services/recommendation/impl/features/FeaturesEngine.cpp
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.o -MF CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.o.d -o CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/features/FeaturesEngine.cpp

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/features/FeaturesEngine.cpp > CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.i

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/features/FeaturesEngine.cpp -o CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.s

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.o: src/libs/services/recommendation/impl/features/FeaturesDefs.cpp
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.o -MF CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.o.d -o CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/features/FeaturesDefs.cpp

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/features/FeaturesDefs.cpp > CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.i

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/features/FeaturesDefs.cpp -o CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.s

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.o: src/libs/services/recommendation/impl/playlist-constraints/ConsecutiveArtists.cpp
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.o -MF CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.o.d -o CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/playlist-constraints/ConsecutiveArtists.cpp

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/playlist-constraints/ConsecutiveArtists.cpp > CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.i

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/playlist-constraints/ConsecutiveArtists.cpp -o CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.s

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.o: src/libs/services/recommendation/impl/playlist-constraints/ConsecutiveReleases.cpp
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.o -MF CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.o.d -o CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/playlist-constraints/ConsecutiveReleases.cpp

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/playlist-constraints/ConsecutiveReleases.cpp > CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.i

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/playlist-constraints/ConsecutiveReleases.cpp -o CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.s

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.o: src/libs/services/recommendation/impl/playlist-constraints/DuplicateTracks.cpp
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.o -MF CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.o.d -o CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/playlist-constraints/DuplicateTracks.cpp

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/playlist-constraints/DuplicateTracks.cpp > CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.i

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/playlist-constraints/DuplicateTracks.cpp -o CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.s

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.o: src/libs/services/recommendation/impl/PlaylistGeneratorService.cpp
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.o -MF CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.o.d -o CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/PlaylistGeneratorService.cpp

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/PlaylistGeneratorService.cpp > CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.i

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/PlaylistGeneratorService.cpp -o CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.s

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/flags.make
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.o: src/libs/services/recommendation/impl/RecommendationService.cpp
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.o: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.o -MF CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.o.d -o CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/RecommendationService.cpp

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/RecommendationService.cpp > CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.i

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/impl/RecommendationService.cpp -o CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.s

# Object files for target lmsrecommendation
lmsrecommendation_OBJECTS = \
"CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.o" \
"CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.o" \
"CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.o" \
"CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.o" \
"CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.o" \
"CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.o" \
"CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.o" \
"CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.o" \
"CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.o"

# External object files for target lmsrecommendation
lmsrecommendation_EXTERNAL_OBJECTS =

src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/clusters/ClustersEngine.cpp.o
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngineCache.cpp.o
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesEngine.cpp.o
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/features/FeaturesDefs.cpp.o
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveArtists.cpp.o
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/ConsecutiveReleases.cpp.o
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/playlist-constraints/DuplicateTracks.cpp.o
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/PlaylistGeneratorService.cpp.o
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/impl/RecommendationService.cpp.o
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/build.make
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/database/liblmsdatabase.dylib
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/som/liblmssom.dylib
src/libs/services/recommendation/liblmsrecommendation.dylib: /usr/local/lib/libwtdbo.4.10.1.dylib
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/utils/liblmsutils.dylib
src/libs/services/recommendation/liblmsrecommendation.dylib: /opt/homebrew/lib/libboost_system-mt.dylib
src/libs/services/recommendation/liblmsrecommendation.dylib: /usr/local/lib/libwt.4.10.1.dylib
src/libs/services/recommendation/liblmsrecommendation.dylib: /opt/homebrew/lib/libboost_thread-mt.dylib
src/libs/services/recommendation/liblmsrecommendation.dylib: /opt/homebrew/lib/libboost_filesystem-mt.dylib
src/libs/services/recommendation/liblmsrecommendation.dylib: /opt/homebrew/lib/libboost_atomic-mt.dylib
src/libs/services/recommendation/liblmsrecommendation.dylib: src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library liblmsrecommendation.dylib"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lmsrecommendation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/build: src/libs/services/recommendation/liblmsrecommendation.dylib
.PHONY : src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/build

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/clean:
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation && $(CMAKE_COMMAND) -P CMakeFiles/lmsrecommendation.dir/cmake_clean.cmake
.PHONY : src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/clean

src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/depend:
	cd /Users/shree/Downloads/Music-Streaming-Service && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shree/Downloads/Music-Streaming-Service /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation /Users/shree/Downloads/Music-Streaming-Service /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/libs/services/recommendation/CMakeFiles/lmsrecommendation.dir/depend

