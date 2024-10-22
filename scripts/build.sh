#!/bin/bash

cmake -S . -B ./build
cmake --build build # --verbose
# cmake --build build --clean-first -v --config Release