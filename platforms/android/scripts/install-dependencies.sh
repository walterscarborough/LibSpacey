#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../../.." || exit 1
}

function install_missing_brew_dependencies() {
brew bundle -v --file=- <<-"EOS"
brew "shellcheck"
EOS
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  install_missing_brew_dependencies

  shared.display_success_message "Android dependencies installed successfully 💾"
}

main
