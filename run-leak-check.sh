if -d if [ -d "build" ]; then
    cd build && make && ASAN_OPTIONS=detect_leaks=1 ./test-lab
else
    echo "Run setup first!"
fi
