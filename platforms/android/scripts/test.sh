#!/usr/bin/env bash

declare EMULATOR_PID=""
declare LOGCAT_PID=""

declare -r AVD_SYSTEM_IMAGE="system-images;android-28;google_apis_playstore;x86"

function go_to_project_top_directory() {
  local -r script_dir=$(dirname "${BASH_SOURCE[0]}")

  cd "$script_dir/../../.." || exit 1
}

function check_if_required_environment_variables_are_set() {
  if [[ -z "$ANDROID_SDK" ]]; then
    echo "Warning: \$ANDROID_SDK environment variable is not set. Please set it to your Android SDK directory path!"
    exit 1
  fi
}

function set_bash_exit_handling() {
  trap stop_emulator_and_logcat EXIT
}

function stop_emulator_and_logcat() {
  kill "$LOGCAT_PID"
  kill "$EMULATOR_PID"
}

function download_avd_system_image() {
  pushd "$ANDROID_SDK"/cmdline-tools/latest/bin || exit 1
  ./sdkmanager "$AVD_SYSTEM_IMAGE"
  popd || exit 1
}

function create_avd_for_emulator() {
  pushd "$ANDROID_SDK"/cmdline-tools/latest/bin || exit 1
  echo "no" | ./avdmanager create avd -n libspacey-test -k "$AVD_SYSTEM_IMAGE" -d "pixel_2_xl" --force
  popd || exit 1
}

function start_emulator() {
  "$ANDROID_SDK"/emulator/emulator -avd libspacey-test -wipe-data &
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

  check_if_required_environment_variables_are_set
  download_avd_system_image
  create_avd_for_emulator

  set_bash_exit_handling
  start_emulator
  unlock_screen
  start_logcat
  run_tests

  shared.display_success_message "Android tests completed successfully 🧪"
}

main
