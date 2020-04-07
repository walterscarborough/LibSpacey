#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../../.." || exit 1
}

function install_missing_brew_dependencies() {
brew bundle -v --file=- <<-"EOS"
brew "emscripten"
brew "shellcheck"
EOS
}

function install_npm_dependencies() {
  pushd platforms/typescript || exit 1
  npm install
  popd || exit 1
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  install_missing_brew_dependencies
  install_npm_dependencies

  shared.display_success_message "TypeScript dependencies installed successfully 💾"
}

main
