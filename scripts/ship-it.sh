#!/usr/bin/env bash

function go_to_root_directory() {
    cd `git rev-parse --show-toplevel`
}

function build_library() {
    ./scripts/build.sh
}

function run_tests() {
    ./scripts/test.sh
}

function push_code() {
    git push
}

function main() {
    go_to_root_directory

    build_library
    run_tests

    push_code
}

main "$@"
