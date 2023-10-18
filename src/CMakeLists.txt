add_library(lab SHARED lab.cpp lab.h)

## This is needed to find the generated headers
target_include_directories(lab PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

## Set compiler flags for the library
target_compile_options(lab PRIVATE
  "$<$<CXX_COMPILER_ID:MSVC>:/W4;/WX>"
  "$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall;-Wextra;-pedantic;>"
)

include(GenerateExportHeader)
generate_export_header(lab)
configure_file(labconfig.h.in labconfig.h)

## Check for common packages needed
#find_package(Threads REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(readline REQUIRED IMPORTED_TARGET readline)
target_link_libraries(lab PRIVATE PkgConfig::readline)

add_sanitizers(lab)

if (COVERAGE)
  include(CodeCoverage)
  append_coverage_compiler_flags()
  setup_target_for_coverage_lcov(
    NAME coverage
    EXECUTABLE test-lab
    DEPENDENCIES
      lab
  )
endif(COVERAGE)
