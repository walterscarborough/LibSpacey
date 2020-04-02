#!/usr/bin/env bash

function shared.set_bash_error_handling() {
  set -o errexit
  set -o errtrace
  set -o nounset
  set -o pipefail
}

function shared.display_success_message() {
  local -r message=$1
  local -r green_color_code='\033[1;32m'
  local -r default_color_code='\033[00m'
  echo -e "${green_color_code}\\n${message} ${default_color_code} \\n"
}
