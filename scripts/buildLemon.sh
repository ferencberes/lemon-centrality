#!/bin/bash

thisDir="$(dirname $0)"
thisDir="$(readlink -f "$thisDir")"

lemonProgramDir="$thisDir"/../src/lemon-1.3.1/build/tools/centrality/

pushd "$lemonProgramDir"
echo "This script only builds /tools/centrality directory of the project!"
make
popd
