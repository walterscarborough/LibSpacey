# LibSpacey

This is a small C++ implementation of the [Supermemo SM2 algorithm](https://www.supermemo.com/english/ol/sm2.htm) for spaced based repetition that focuses on simplicity, portability, and testability.

It can also be built as an xcode dynamic framework for iOS. 

[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)

## Using in Xcode / iOS Projects

LibSpacey can be added to your xcode project via [carthage](https://github.com/Carthage/Carthage).

Just add this line to your cartfile:

```
github "walterscarborough/LibSpacey" "<current-tagged-release>"
```

## Using in Other C++ Projects

LibSpacey uses cmake to handle building and compilation, and [conan](https://github.com/conan-io/conan) for C++ package management.

### Build / Run Guide

1.) Build app
```
./scripts/build.sh
```

2.) Run tests
```
./scripts/test.sh
```

3.) (optional) Run sample app

```
./cmake-build-debug/bin/flashcardEngineApp
```

## Contributions

Contributions are welcome! Feel free to submit a pull request.

### License

MIT -- full license file included in this repo.
