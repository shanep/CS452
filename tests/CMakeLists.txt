## Look for a local gtest install and download if necessary
find_package(GTest CONFIG REQUIRED)

add_executable(test-lab test-lab.cpp)
target_link_libraries(test-lab PRIVATE lab GTest::gtest_main)
add_sanitizers(test-lab)

include(GoogleTest)
gtest_discover_tests(test-lab)
