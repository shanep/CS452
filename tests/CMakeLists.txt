## Look for a local gtest install and download if necessary
find_package(GTest CONFIG QUIET)
if(${GTest_FOUND})
  message(STATUS "Found local install of gtest")
else()
  message(STATUS "Downloading googletest from git repo")
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG    03597a01ee50ed33e9dfd640b249b4be3799d395
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif(${GTest_FOUND})


add_executable(test-lab test-lab.cpp)
target_link_libraries(test-lab lab GTest::gtest_main)
add_sanitizers(test-lab)

include(GoogleTest)
gtest_discover_tests(test-lab)
