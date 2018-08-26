#!/usr/bin/env bash

function go_to_root_directory() {
    cd `git rev-parse --show-toplevel`
}

function build_library() {
    go_to_root_directory
    cd cmake-build-debug
    cmake ../
    make
    go_to_root_directory
}

function run_tests() {
    go_to_root_directory
    cd cmake-build-debug/bin
    ./run_test
}

function main() {
    build_library
    run_tests
}

main "$@"
