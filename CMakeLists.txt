cmake_minimum_required(VERSION 3.20)

# Don't allow in-source building
if (CMAKE_BINARY_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  message(FATAL_ERROR "Building in-source is not supported! Create a build dir and remove ${CMAKE_SOURCE_DIR}/CMakeCache.txt")
endif()

project(lab LANGUAGES CXX VERSION 0.1)

# Set up project wide defaults
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (CMAKE_CXX_COMPILER)
  set(CMAKE_CXX_COMPILER ${CMAKE_CXX_COMPILER})
endif()


## Identify debug vs release builds with a postfix
set(CMAKE_DEBUG_POSTFIX d)

## Options
option(COVERAGE "Compile for code coverage using lcov" OFF)
option(ADDRESS_SANITIZER "Add address sanitizer to debug build" OFF)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})


## Add address sanatizers for debug build only!
if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND ADDRESS_SANITIZER)
  set(SANITIZE_ADDRESS TRUE)
  find_package(Sanitizers)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug" AND ADDRESS_SANITIZER)

## Add the src to the build
add_subdirectory(src)
add_subdirectory(app)

## Add the tests to the build
enable_testing()
add_subdirectory(tests)
