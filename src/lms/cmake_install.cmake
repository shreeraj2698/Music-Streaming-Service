# Install script for directory: /Users/shree/Downloads/Music-Streaming-Service/src/lms

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/shree/Downloads/Music-Streaming-Service")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/shree/Downloads/Music-Streaming-Service/src/lms/lms")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lms" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lms")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/subsonic"
      -delete_rpath "/usr/local/lib"
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/services/auth"
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/services/scanner"
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/services/recommendation"
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/services/scrobbling"
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/services/cover"
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/av"
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/services/database"
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/image"
      -delete_rpath "/Users/shree/Downloads/Music-Streaming-Service/src/libs/utils"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lms")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/lms")
    endif()
  endif()
endif()

