#!/bin/bash

cmake -S . -B ./build
cmake --build ./build --fresh --clean-first --verbose # --target utils_library