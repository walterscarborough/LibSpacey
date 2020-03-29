#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/.." || exit 1
}

function run_bash_linter() {
  shellcheck -x scripts/*.sh
}

function run_clang_tidy_check() {
  pushd src || exit 1
  bash -c "clang-tidy --warnings-as-errors=* -checks=modernize*,cppcoreguidelines*,clang-analyzer*,hicpp*,portability*,readability* -header-filter=.* *.cpp -- -std=c++17"
  popd || exit 1
}

function display_success_message() {
  local -r green_color_code='\033[1;32m'
  local -r default_color_code='\033[00m'
  echo -e "${green_color_code}\\nLinters ran successfully 🧹 ${default_color_code} \\n"
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  run_bash_linter
  run_clang_tidy_check

  shared.display_success_message "Linters ran successfully 🧹"
}

main
