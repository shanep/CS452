if [ ! -d "build" ]; then
    ./configure-sanitize
fi

cmake --build build
./build/test-lab --gtest_filter=SegFaultTest.* 2>&1 | tee segfault.log