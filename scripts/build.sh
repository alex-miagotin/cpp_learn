#!/bin/bash

cmake -S . -B ./build
cmake --build build --verbose

# unameOut="$(uname -s)"
# case "${unameOut}" in
#     Linux*)     
#         machine=Linux
#         cmake --build build --verbose
#         echo "Linux build ran";;
#     Darwin*)    
#         machine=Mac;;
#     CYGWIN*)    
#         machine=Cygwin;;
#     MINGW*)     
#         cmake --build build --verbose
#         machine=MinGw;;
#     MSYS_NT*)   
#         machine=Git;;
#     *)          
#         machine="UNKNOWN:${unameOut}"
# esac