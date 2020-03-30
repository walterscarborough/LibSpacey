#!/usr/bin/env bash

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../.." || exit 1
}

function prepare_emscripten_build_directory() {
  rm -rf typescript/build-emscripten
  mkdir -p typescript/build-emscripten
}

function prepare_emscripten_dist_directory() {
  rm -rf typescript/dist-emscripten
  mkdir -p typescript/dist-emscripten
}

function build_webidl_bindings() {
  pushd typescript/build-emscripten || exit 1
  python /usr/local/Cellar/emscripten/*/libexec/tools/webidl_binder.py \
    ../src-emscripten/flashcard.idl \
    flashcard-wrapper-glue
  popd || exit 1
}

function compile_emscripten() {
  pushd typescript || exit 1
  emcc ../common/src/flashcard.cpp \
    ../common/src/srsengine.cpp \
    src-emscripten/flashcard-wrapper.cpp \
    --post-js build-emscripten/flashcard-wrapper-glue.js \
    --emit-symbol-map \
    -s MODULARIZE=1 \
    -s 'EXPORT_NAME="FlashcardModule"' \
    -o dist-emscripten/libspacey-flashcard-module.js
  popd || exit 1
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  prepare_emscripten_build_directory
  prepare_emscripten_dist_directory
  build_webidl_bindings
  compile_emscripten

  shared.display_success_message "Build completed successfully 🏗️"
}

main
