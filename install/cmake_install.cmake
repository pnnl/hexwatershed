# Install script for directory: /people/liao313/workspace/cplus/hexwatershed/hexwatershed

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/people/liao313/workspace/cplus/hexwatershed/hexwatershed/../hexwatershed/bin/hexwatershed" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/people/liao313/workspace/cplus/hexwatershed/hexwatershed/../hexwatershed/bin/hexwatershed")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/people/liao313/workspace/cplus/hexwatershed/hexwatershed/../hexwatershed/bin/hexwatershed"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/people/liao313/workspace/cplus/hexwatershed/hexwatershed/../hexwatershed/bin/hexwatershed")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/people/liao313/workspace/cplus/hexwatershed/hexwatershed/../hexwatershed/bin" TYPE EXECUTABLE FILES "/people/liao313/workspace/cplus/hexwatershed/hexwatershed/hexwatershed")
  if(EXISTS "$ENV{DESTDIR}/people/liao313/workspace/cplus/hexwatershed/hexwatershed/../hexwatershed/bin/hexwatershed" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/people/liao313/workspace/cplus/hexwatershed/hexwatershed/../hexwatershed/bin/hexwatershed")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/people/liao313/workspace/cplus/hexwatershed/hexwatershed/../hexwatershed/bin/hexwatershed"
         OLD_RPATH "/share/apps/gdal/2.3.1/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/share/apps/binutils/2.24/bin/strip" "$ENV{DESTDIR}/people/liao313/workspace/cplus/hexwatershed/hexwatershed/../hexwatershed/bin/hexwatershed")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/people/liao313/workspace/cplus/hexwatershed/hexwatershed/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
