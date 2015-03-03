#!/bin/bash -eu

trap "echo Some errors occurred while installing dependencies. Exiting." ERR

SCRIPT_DIR=$(readlink -f $(dirname "$0"))

# dependencies will be deployed in this directory
mkdir -p "$SCRIPT_DIR"/../../dep

"$SCRIPT_DIR"/install_gtest.sh
"$SCRIPT_DIR"/install_lemon.sh
