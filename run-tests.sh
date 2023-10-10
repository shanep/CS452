if -d if [ -d "build" ]; then
    cd build && make
else
    echo "Run setup first!"
fi
