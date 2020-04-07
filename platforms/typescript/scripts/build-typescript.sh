#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../../.." || exit 1
}

function prepare_typescript_build_directory() {
  rm -rf platforms/typescript/dist
}

function build_typescript() {
  pushd platforms/typescript || exit 1
  npm run build
  popd || exit 1
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  prepare_typescript_build_directory
  build_typescript

  shared.display_success_message "Typescript build completed successfully 🏗️"
}

main
