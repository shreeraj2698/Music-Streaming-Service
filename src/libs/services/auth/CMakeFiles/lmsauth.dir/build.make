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
include src/libs/services/auth/CMakeFiles/lmsauth.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/libs/services/auth/CMakeFiles/lmsauth.dir/compiler_depend.make

# Include the progress variables for this target.
include src/libs/services/auth/CMakeFiles/lmsauth.dir/progress.make

# Include the compile flags for this target's objects.
include src/libs/services/auth/CMakeFiles/lmsauth.dir/flags.make

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/flags.make
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.o: src/libs/services/auth/impl/AuthTokenService.cpp
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.o -MF CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.o.d -o CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/AuthTokenService.cpp

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/AuthTokenService.cpp > CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.i

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/AuthTokenService.cpp -o CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.s

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/flags.make
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.o: src/libs/services/auth/impl/AuthServiceBase.cpp
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.o -MF CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.o.d -o CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/AuthServiceBase.cpp

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/AuthServiceBase.cpp > CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.i

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/AuthServiceBase.cpp -o CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.s

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/EnvService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/flags.make
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/EnvService.cpp.o: src/libs/services/auth/impl/EnvService.cpp
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/EnvService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/EnvService.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/EnvService.cpp.o -MF CMakeFiles/lmsauth.dir/impl/EnvService.cpp.o.d -o CMakeFiles/lmsauth.dir/impl/EnvService.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/EnvService.cpp

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/EnvService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsauth.dir/impl/EnvService.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/EnvService.cpp > CMakeFiles/lmsauth.dir/impl/EnvService.cpp.i

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/EnvService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsauth.dir/impl/EnvService.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/EnvService.cpp -o CMakeFiles/lmsauth.dir/impl/EnvService.cpp.s

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/flags.make
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.o: src/libs/services/auth/impl/LoginThrottler.cpp
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.o -MF CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.o.d -o CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/LoginThrottler.cpp

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/LoginThrottler.cpp > CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.i

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/LoginThrottler.cpp -o CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.s

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/flags.make
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.o: src/libs/services/auth/impl/PasswordServiceBase.cpp
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.o -MF CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.o.d -o CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/PasswordServiceBase.cpp

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/PasswordServiceBase.cpp > CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.i

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/PasswordServiceBase.cpp -o CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.s

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/flags.make
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.o: src/libs/services/auth/impl/http-headers/HttpHeadersEnvService.cpp
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.o -MF CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.o.d -o CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/http-headers/HttpHeadersEnvService.cpp

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/http-headers/HttpHeadersEnvService.cpp > CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.i

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/http-headers/HttpHeadersEnvService.cpp -o CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.s

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/flags.make
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.o: src/libs/services/auth/impl/internal/InternalPasswordService.cpp
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.o -MF CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.o.d -o CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/internal/InternalPasswordService.cpp

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/internal/InternalPasswordService.cpp > CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.i

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/internal/InternalPasswordService.cpp -o CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.s

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/flags.make
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.o: src/libs/services/auth/impl/pam/PAMPasswordService.cpp
src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.o: src/libs/services/auth/CMakeFiles/lmsauth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.o"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.o -MF CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.o.d -o CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.o -c /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/pam/PAMPasswordService.cpp

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.i"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/pam/PAMPasswordService.cpp > CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.i

src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.s"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/impl/pam/PAMPasswordService.cpp -o CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.s

# Object files for target lmsauth
lmsauth_OBJECTS = \
"CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.o" \
"CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.o" \
"CMakeFiles/lmsauth.dir/impl/EnvService.cpp.o" \
"CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.o" \
"CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.o" \
"CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.o" \
"CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.o" \
"CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.o"

# External object files for target lmsauth
lmsauth_EXTERNAL_OBJECTS =

src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthTokenService.cpp.o
src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/AuthServiceBase.cpp.o
src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/EnvService.cpp.o
src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/LoginThrottler.cpp.o
src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/PasswordServiceBase.cpp.o
src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/http-headers/HttpHeadersEnvService.cpp.o
src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/internal/InternalPasswordService.cpp.o
src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/impl/pam/PAMPasswordService.cpp.o
src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/build.make
src/libs/services/auth/liblmsauth.dylib: src/libs/services/database/liblmsdatabase.dylib
src/libs/services/auth/liblmsauth.dylib: /Library/Developer/CommandLineTools/SDKs/MacOSX14.0.sdk/usr/lib/libpam.tbd
src/libs/services/auth/liblmsauth.dylib: /Library/Developer/CommandLineTools/SDKs/MacOSX14.0.sdk/usr/lib/libdl.tbd
src/libs/services/auth/liblmsauth.dylib: src/libs/utils/liblmsutils.dylib
src/libs/services/auth/liblmsauth.dylib: /opt/homebrew/lib/libboost_system-mt.dylib
src/libs/services/auth/liblmsauth.dylib: /usr/local/lib/libwt.4.10.1.dylib
src/libs/services/auth/liblmsauth.dylib: /opt/homebrew/lib/libboost_thread-mt.dylib
src/libs/services/auth/liblmsauth.dylib: /opt/homebrew/lib/libboost_filesystem-mt.dylib
src/libs/services/auth/liblmsauth.dylib: /opt/homebrew/lib/libboost_atomic-mt.dylib
src/libs/services/auth/liblmsauth.dylib: /usr/local/lib/libwtdbo.4.10.1.dylib
src/libs/services/auth/liblmsauth.dylib: src/libs/services/auth/CMakeFiles/lmsauth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/shree/Downloads/Music-Streaming-Service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library liblmsauth.dylib"
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lmsauth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libs/services/auth/CMakeFiles/lmsauth.dir/build: src/libs/services/auth/liblmsauth.dylib
.PHONY : src/libs/services/auth/CMakeFiles/lmsauth.dir/build

src/libs/services/auth/CMakeFiles/lmsauth.dir/clean:
	cd /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth && $(CMAKE_COMMAND) -P CMakeFiles/lmsauth.dir/cmake_clean.cmake
.PHONY : src/libs/services/auth/CMakeFiles/lmsauth.dir/clean

src/libs/services/auth/CMakeFiles/lmsauth.dir/depend:
	cd /Users/shree/Downloads/Music-Streaming-Service && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shree/Downloads/Music-Streaming-Service /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth /Users/shree/Downloads/Music-Streaming-Service /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth /Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth/CMakeFiles/lmsauth.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/libs/services/auth/CMakeFiles/lmsauth.dir/depend

