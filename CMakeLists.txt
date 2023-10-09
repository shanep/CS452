cmake_minimum_required(VERSION 3.15)

# Don't allow in-source building
if (CMAKE_BINARY_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  message(FATAL_ERROR "Building in-source is not supported! Create a build dir and remove ${CMAKE_SOURCE_DIR}/CMakeCache.txt")
endif()

project(lab LANGUAGES C VERSION 0.1)

## Set C standard
set(C_STANDARD 11)
set(C_STANDARD_REQUIRED ON)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

## Identify debug vs release builds with a postfix
## Add address sanatizers for debug build only!
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(SANITIZE_ADDRESS TRUE)
  find_package(Sanitizers)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

## Add the src to the build
add_subdirectory(src)

## Add the tests to the build
enable_testing()
add_subdirectory(tests)
add_subdirectory(unity)
include(CTest)
