#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../.." || exit 1
}

function delete_xcode_derived_data() {
  rm -rf ~/Library/Developer/Xcode/DerivedData
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  delete_xcode_derived_data

  shared.display_success_message "Deleted Xcode derived data 🤦"
}

main
