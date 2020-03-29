#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/.." || exit 1
}

function build_library() {
  pushd cmake-build-debug || exit 1
  cmake ../
  make
  popd || exit 1
}

function run_tests() {
  pushd cmake-build-debug/bin || exit 1
  ./run_test
  popd || exit 1
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  build_library
  run_tests

  shared.display_success_message "Tests completed successfully 🧪"
}

main
