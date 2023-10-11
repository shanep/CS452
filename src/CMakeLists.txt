add_library(lab SHARED lab.cpp lab.h)
add_library(labstatic STATIC lab.cpp lab.h)

target_include_directories(lab PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_include_directories(labstatic PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

## Set compiler flags for the library
target_compile_options(lab PRIVATE
  "$<$<CXX_COMPILER_ID:MSVC>:/W4;/WX>"
  "$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall;-Wextra;-Werror;-pedantic;>"
)

include(GenerateExportHeader)
generate_export_header(lab BASE_NAME libshared_and_static)
set_target_properties(labstatic PROPERTIES COMPILE_FLAGS -DLIBSHARED_AND_STATIC_STATIC_DEFINE)
configure_file(labconfig.h.in labconfig.h)

## Check for common packages needed
find_package(Readline REQUIRED)
find_package(Threads REQUIRED)

target_link_libraries(labstatic PUBLIC readline)
target_link_libraries(lab PUBLIC readline)
target_link_libraries(labstatic PUBLIC Threads::Threads)
target_link_libraries(lab PUBLIC Threads::Threads)

## Add code coverage flags for debug build only!
if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND COVERAGE AND NOT ADDRESS_SANITIZER)
  set(COVERAGE TRUE)
  include(CodeCoverage)
  #append_coverage_compiler_flags_to_target(lab)
  append_coverage_compiler_flags()
  setup_target_for_coverage_lcov(
    NAME coverage
    EXECUTABLE test-lab
    DEPENDENCIES
      lab
  )
endif(CMAKE_BUILD_TYPE STREQUAL "Debug" AND COVERAGE AND NOT ADDRESS_SANITIZER)