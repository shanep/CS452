add_executable(myprogram main.c)

## Link the library to the executable to create the final binary
target_link_libraries(myprogram lab)

## Add address sanatizers for debug build only!
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_sanitizers(myprogram)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")