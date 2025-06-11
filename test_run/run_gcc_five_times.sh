#!/bin/bash

for i in {1..5}; do
    echo "=============================="
    echo "Run #$i: Starting test_run_clang.sh"
    ./test_run_gcc.sh
    echo "Run #$i: Finished"
    echo
done
