if [ ! -d "build" ]; then
    ./configure-coverage
fi

cmake --build build --target coverage
