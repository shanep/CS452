add_executable(test-lab test-lab.c)

## Link the unit tester to the shared library so we can easily test student
## submissions against the reference implementation.
target_link_libraries(test-lab PRIVATE lab unity)

## Add address sanatizers for debug build only!
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_sanitizers(test-lab)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")
