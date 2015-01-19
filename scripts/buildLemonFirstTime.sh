#!/bin/bash

thisDir="$(dirname $0)"
thisDir="$(readlink -f "$thisDir")"

lemonDir="$thisDir"/../src/lemon-1.3.1/
pushd "$lemonDir"
mkdir -p build
cd build
cmake ..
make
popd
