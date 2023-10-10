add_library(lab SHARED lab.c lab.h)
add_library(labstatic STATIC lab.c lab.h)

target_include_directories(lab PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_include_directories(labstatic PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

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