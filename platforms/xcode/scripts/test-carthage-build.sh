#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../../.." || exit 1
}

function clean_old_carthage_build() {
  rm -f LibSpacey.framework.zip
}

function test_build_with_carthage() {
  carthage build --archive

  if [[ ! -f "LibSpacey.framework.zip" ]]; then
    echo "Carthage build failure: LibSpacey.framework.zip was not created"
  fi

  rm "LibSpacey.framework.zip"
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  clean_old_carthage_build
  test_build_with_carthage

  shared.display_success_message "Xcode carthage build ran successfully 🏗️"
}

main
