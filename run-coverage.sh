if [ -d "build" ]; then
    ./clean.sh
fi

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCOVERAGE=ON ..
make coverage
