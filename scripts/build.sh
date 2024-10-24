#!/bin/bash

cmake -S . -B ./build

unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     
        machine=Linux
        cmake --build build # --verbose
        echo "Linux build ran";;
    Darwin*)    
        machine=Mac;;
    CYGWIN*)    
        machine=Cygwin;;
    MINGW*)     
        cmake --build build -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake"
        machine=MinGw;;
    MSYS_NT*)   
        machine=Git;;
    *)          
        machine="UNKNOWN:${unameOut}"
esac