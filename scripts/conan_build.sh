#!/bin/bash

# conan profile detect --force
# conan profile path default
# conan install . --output-folder=build --build=missing

if ! command -v conan &>/dev/null; then
    echo "conan could not be found, installing..."
    python3 -m ensurepip --default-pip
    pip3 install conan
fi

# check if conan profile exists using conan profile list and grep   
if ! conan profile list | grep -q "default"; then
    echo "conan profile not found, creating default..."
    conan profile detect
fi

conan install . -c tools.cmake.cmaketoolchain:generator=Ninja --output-folder=build --build=missing --settings=compiler.cppstd=20