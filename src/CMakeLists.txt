add_library(lab SHARED lab.cpp lab.h)

## This is needed to find the generated headers
target_include_directories(lab PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

## Set compiler flags for the library
target_compile_options(lab PRIVATE
  "$<$<CXX_COMPILER_ID:MSVC>:/W4;/WX>"
  "$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall;-Wextra;-Werror;-pedantic;>"
)

include(GenerateExportHeader)
generate_export_header(lab)
configure_file(labconfig.h.in labconfig.h)

## Check for common packages needed
find_package(Readline REQUIRED)
#find_package(Threads REQUIRED)

#target_link_libraries(labstatic PUBLIC readline)
#target_link_libraries(labstatic PUBLIC Threads::Threads)

target_include_directories(lab PUBLIC ${Readline_INCLUDE_DIR})
target_link_libraries(lab PUBLIC ${Readline_LIBRARY})
#target_link_libraries(lab PUBLIC Threads::Threads)

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
