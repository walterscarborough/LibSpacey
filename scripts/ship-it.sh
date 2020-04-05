#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/.." || exit 1
}

function push_code() {
  git push
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  ./common/scripts/validate.sh
  ./xcode/scripts/validate.sh
  ./typescript/scripts/validate.sh

  push_code
}

main
