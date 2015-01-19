#!/bin/bash

thisDir="$(dirname $0)"
thisDir="$(readlink -f "$thisDir")"

lemonProgramDir="$thisDir"/../src/lemon-1.3.1/build/tools/centrality/

pushd "$lemonProgramDir"
echo "This script only runs /tools/centrality/centrality_test2.cpp file, for now..!"

if [ "$#" -ne 1 ]; then
  echo "Usage: runLemonTest <input>"
else
./centrality_test "$1"
fi

popd
