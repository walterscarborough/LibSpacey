#!/usr/bin/env bash

function push_code() {
  git push
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  ./scripts/build.sh
  ./scripts/test.sh

  push_code
}

main
