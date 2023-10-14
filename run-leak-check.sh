if [ ! -d "build" ]; then
    ./configure-sanitize
fi

cmake --build build
export ASAN_OPTIONS=detect_leaks=1
./build/test-lab
