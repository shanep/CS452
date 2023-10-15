if [ ! -d "build" ]; then
    ./configure-sanitize
fi

cmake --build build
export ASAN_OPTIONS=check_initialization_order=1.
export ASAN_OPTIONS=detect_leaks=1
./build/test-lab --gtest_filter=LeakTest.* 2>&1 | tee leak-check.log
