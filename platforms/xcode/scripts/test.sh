#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../../.." || exit 1
}

function run_tests() {
  pushd platforms/xcode || exit 1

  xcodebuild clean test \
    -project LibSpacey.xcodeproj \
    -scheme LibSpacey \
    -destination 'platform=iOS Simulator,name=iPhone 11,OS=13.4' \
    | xcpretty

  popd || exit 1
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  run_tests

  shared.display_success_message "Xcode tests ran successfully 🧪"
}

main
