# LibSpacey

[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)

This is a small C++ implementation of the [Supermemo SM2 algorithm](https://www.supermemo.com/english/ol/sm2.htm) for spaced based repetition that focuses on simplicity, portability, and testability.

It also supports the following platforms:
* iOS
* Android
* TypeScript 

## Project Overview

### Scripts

Every platform that LibSpacey supports includes the following scripts:

| Name | Description |
|---|---|
| test.sh | Runs all tests | 
| lint.sh | Runs all available linters  | 
| validate.sh | Runs tests, linters, and build (when available) |
| install-dependencies.sh | Installs dependencies needed to build, lint, and run tests |

### Development Environment

The scripts in this project assume that you are using:
* macos Catalina or greater
* homebrew
* node.js 13 or greater
* xcode 11.4 or greater
 
The `install-dependencies.sh` scripts will take care of all basic dependencies except for xcode and node.js.
Some people prefer to use specific node.js versions, so I've left that up to you to decide what you want to use.
You can install xcode via the macos app store.
 
Most scripts will probably work in a different unix (e.g. Linux or FreeBSD) except for the `install-dependencies.sh` scripts. 

### Installing Dependencies

To install dependencies for all platforms run:

```bash
./scripts/install-dependencies.sh
```

Otherwise, feel free to go to any platform directory and run the local script there (e.g. for TypeScript):

```bash
./platforms/typescript/scripts/install-dependencies.sh
```

### Ship-It

Please run the `ship-it` script before pushing any new code.
It will automatically run all available tests, linters, and builds for each platform.

```bash
./scripts/ship-it.sh
```


## iOS

LibSpacey includes a light wrapper to bridge C++ into Swift / Objective C. 
This allows it to be built as a framework in xcode that you can call in your projects.

### iOS - Setup

You can add LibSpacey to your project with [carthage](https://github.com/Carthage/Carthage).

Just add this line to your project's cartfile:

```
github "walterscarborough/LibSpacey" "1.1.0"
```

### iOS - Integration / Usage

Feel free to use the `LibSpaceyFlashcard` in your project, and use it with `FlashcardGraderWrapper.gradeFlashcard(...)` whenever you need to grade a flashcard.   

```swift
// Example:

let flashcardWrapper = FlashcardWrapper()

let gradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(
    flashcardWrapper, 
    grade: Grade.Unknown, 
    currentDate: Date()
)
```

### iOS - Running Tests 

```bash
./platforms/xcode/scripts/test.sh
```

### iOS - Building Locally with Carthage

Carthage can automatically build frameworks locally.
It does this by searching recursively for a `.xcodeproj` file and building it.

Just run this command from the LibSpacey repo top level directory: 

```bash
carthage build --archive
```

It will output a `LibSpacey.framework.zip` file in the top level directory.

## Android

LibSpacey uses a light wrapper to bridge C++ into the JVM via JNI as an Android library.
Because of this, it needs to be built separately for each architecture that you want to run it on.
Android Studio should handle this automatically.

### Android - Setup

You can add LibSpacey to your project by copying it into your Android Studio project folder and adding it as a gradle subproject.

### Android - Integration / Usage

```kotlin
// Example

val october_24_2016: Long = 1477294292
val october_25_2016: Long = 1477380692

val flashcardWrapper = FlashcardWrapper(
    previousDate = october_24_2016,
    nextDate = october_24_2016
)

val currentDate = Date.from(Instant.ofEpochSecond(october_24_2016))
val actualGradedFlashcardWrapper = FlashcardWrapperGrader.gradeFlashcardWrapper(
    flashcardWrapper = flashcardWrapper,
    grade = Grade.Unknown,
    currentDate = currentDate
)
```

### Android - Running Tests

```bash
./platforms/android/scripts/test.sh
```

## TypeScript

LibSpacey uses a light wrapper to bridge C++ into JavaScript by using [emscripten](https://emscripten.org/).
It also includes typings so that it can be incorporated into TypeScript projects.

### TypeScript - Setup

For now, you can add LibSpacey to your project by building it and copying it into your project directory.
It will eventually be published to NPM.

### TypeScript - Integration / Usage

```typescript
// Example

const october_24_2016 = 1477294292;
const october_25_2016 = 1477380692;

const flashcard: FlashcardWrapper = {
  repetition: 0,
  interval: 1,
  easinessFactor: 2.5,
  previousDate: october_24_2016,
  nextDate: october_24_2016,
};

const flashcardModuleWrapper = new FlashcardWrapperGrader();
const actualGradedFlashcard = await flashcardModuleWrapper.gradeFlashcard(
  flashcard,
  Grade.Unknown,
  october_24_2016
);
```

### TypeScript - Running Tests

```bash
./platforms/typescript/scripts/test.sh
```

## Using in Other C++ Projects

LibSpacey uses cmake to handle building and compilation, and [conan](https://github.com/conan-io/conan) for C++ package management.

### Build / Run Guide

1.) Build app
```
./common/scripts/build.sh
```

2.) Run tests
```
./common/scripts/test.sh
```

3.) Run linters
```
./common/scripts/lint.sh
```

3.) (optional) Run sample app

```
cd common
./scripts/build.sh
./cmake-build-debug/bin/libSpaceySampleApp
```

## Contributions

Contributions are welcome! Feel free to submit a pull request.

### License

MIT -- full license file included in this repo.
