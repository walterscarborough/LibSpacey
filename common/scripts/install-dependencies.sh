#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../.." || exit 1
}

function install_missing_brew_dependencies() {
  if [[ -f /usr/local/bin/clang-tidy ]]; then
    unlink /usr/local/bin/clang-tidy
  fi

  if [[ -f /usr/local/bin/clang-format ]]; then
    unlink /usr/local/bin/clang-format
  fi

brew bundle -v --file=- <<-"EOS"
brew "conan"
brew "llvm"
brew "shellcheck"
EOS

  ln -s "$(brew --prefix llvm)/bin/clang-tidy" "/usr/local/bin/clang-tidy"
  ln -s "$(brew --prefix llvm)/bin/clang-format" "/usr/local/bin/clang-format"
}

function install_missing_conan_dependencies() {
  pushd common || exit 1

  conan install . -s build_type=Debug --install-folder=cmake-build-debug
  conan install . -s build_type=Release --install-folder=cmake-build-release

  popd || exit 1
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  install_missing_brew_dependencies
  install_missing_conan_dependencies

  shared.display_success_message "Common dependencies installed successfully 💾"
}

main
