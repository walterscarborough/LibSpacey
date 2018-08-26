#!/usr/bin/env bash

function go_to_root_directory() {
    cd `git rev-parse --show-toplevel`
}

function remove_build_directory() {
    go_to_root_directory
    bash -c '[ -d cmake-build-debug ] && rm -r cmake-build-debug'
}

function install_conan_dependencies() {
    conan install . -s build_type=Debug --install-folder=cmake-build-debug
    conan install . -s build_type=Release --install-folder=cmake-build-release
}

function build_library() {
    go_to_root_directory
    cd cmake-build-debug
    cmake ../
    make
    go_to_root_directory
}

function main() {
    remove_build_directory
    install_conan_dependencies
    build_library
}

main "$@"
