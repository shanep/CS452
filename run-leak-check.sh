if [ ! -d "build" ]; then
    ./configure-debug-as
fi

cmake --build build
export ASAN_OPTIONS=detect_leaks=1
./build/test-lab
