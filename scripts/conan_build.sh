#!/bin/bash

# conan profile detect --force
# conan profile path default
# conan install . --output-folder=build --build=missing

conan install . -c tools.cmake.cmaketoolchain:generator=Ninja --output-folder=build --build=missing --settings=compiler.cppstd=20