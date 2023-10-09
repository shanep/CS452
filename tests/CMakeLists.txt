add_executable(test-lab test-lab.c)

## Link the unit tester to the static build so we don't have to worry about
## LD_PRELOAD issues when running the tests with address sanatizers.
target_link_libraries(test-lab PRIVATE labstatic unity)


## Add address sanatizers for debug build only!
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_sanitizers(test-lab)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")
