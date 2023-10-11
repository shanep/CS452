if [ -d "build" ]; then
    echo "Configure project or run ./setup.sh first!"
    exit 1
fi

cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCOVERAGE=ON ..
make coverage
