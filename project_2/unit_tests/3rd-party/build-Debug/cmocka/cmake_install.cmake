# Install script for directory: /home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/cmocka

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Debug")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pkgconfig")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/pkgconfig/cmocka.pc")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/pkgconfig" TYPE FILE FILES "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/cmocka.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pkgconfig")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "devel")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/cmake/cmocka/cmocka-config.cmake;/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/cmake/cmocka/cmocka-config-version.cmake")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/lib/cmake/cmocka" TYPE FILE FILES
    "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/cmocka-config.cmake"
    "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/cmocka-config-version.cmake"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "devel")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/doc/cmake_install.cmake")
  INCLUDE("/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/include/cmake_install.cmake")
  INCLUDE("/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/src/cmake_install.cmake")
  INCLUDE("/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/example/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/vishal/Documents/Study_Master/Embedded_Software_Essential/repos/ecen5013/tutorials/unit_tests/3rd-party/build-Debug/cmocka/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
