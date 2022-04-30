#!/bin/bash
rm -rf CMakeCache.txt
module load cmake/3.11.4
module load gcc/8.1.0
cmake CMakeLists.txt
make install
