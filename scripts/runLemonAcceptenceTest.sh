#!/bin/bash

thisDir="$(dirname $0)"
thisDir="$(readlink -f "$thisDir")"

echo "$thisDir" 

lemonProgramDir="src/lemon-1.3.1/build/tools/centrality"
centralityDir="src/lemon-1.3.1/tools/centrality"

pushd "$thisDir"/../"$lemonProgramDir"
programDir="$(dirname .)"
programDir="$(readlink -f "$programDir")"
popd
echo "$programDir"

pushd "$thisDir"/../"$centralityDir"
inputDir="$(dirname .)"
inputDir="$(readlink -f "$inputDir")"
popd
echo "$inputDir"

echo "This script tests the ListDigraphForCentrality class with its functions for a fixed input."
"$lemonProgramDir"/centrality_acceptence_test "$inputDir"/digraph.lgf

