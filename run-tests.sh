if [ ! -d "build" ]; then
    ./configure-debug-as
fi

cmake --build build && ctest --test-dir build --verbose