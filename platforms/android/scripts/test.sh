#!/usr/bin/env bash

declare EMULATOR_PID=""
declare LOGCAT_PID=""

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../../.." || exit 1
}

function set_bash_exit_handling() {
  trap stop_emulator_and_logcat EXIT
}

function stop_emulator_and_logcat() {
  kill $LOGCAT_PID
  kill $EMULATOR_PID
}

function start_emulator() {
  "$ANDROID_SDK"/emulator/emulator -avd Pixel_2_API_28 -wipe-data &
  EMULATOR_PID=$!

  local -r wait_cmd="$ANDROID_SDK/platform-tools/adb wait-for-device shell getprop init.svc.bootanim"
  until $wait_cmd | grep -m 1 stopped; do
    echo "Waiting for Android emulator to start..."
    sleep 1
  done
}

function unlock_screen() {
  "$ANDROID_SDK"/platform-tools/adb shell input keyevent 82
}

function start_logcat() {
  pushd platforms/android || exit 1

  "$ANDROID_SDK"/platform-tools/adb logcat -c
  "$ANDROID_SDK"/platform-tools/adb logcat > build/logcat.log &
  LOGCAT_PID=$!

  popd || exit 1
}

function run_tests() {
  pushd platforms/android || exit 1

  ./gradlew connectedAndroidTest -i

  popd || exit 1
}

function main() {
  go_to_project_top_directory
  source ./scripts/shared/shared.sh || exit 1
  shared.set_bash_error_handling

  set_bash_exit_handling
  start_emulator
  unlock_screen
  start_logcat
  run_tests

  shared.display_success_message "Android tests completed successfully 🧪"
}

main
