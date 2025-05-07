#!/bin/bash

# Create the build directory if it doesn't exist
if [ ! -d "build" ]; then
  echo "Creating build directory..."
  mkdir build
fi

# Enter the build directory
cd build

# Run cmake ..
echo "Running cmake .."
cmake ..

# Exit the build directory
cd ..

# Run make
echo "Running make"
make
