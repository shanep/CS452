include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG    03597a01ee50ed33e9dfd640b249b4be3799d395
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test-lab test-lab.cpp)

## Link the unit tester to the shared library so we can easily test student
## submissions against the reference implementation.
target_link_libraries(test-lab lab GTest::gtest_main)

## Add address sanatizers for debug build only!
if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND ADDRESS_SANITIZER)
  add_sanitizers(test-lab)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug" AND ADDRESS_SANITIZER)

include(GoogleTest)
gtest_discover_tests(test-lab)


