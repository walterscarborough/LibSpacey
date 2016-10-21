# LibSpacey

This is a small C++ implementation of the [Supermemo SM2 algorithm](https://www.supermemo.com/english/ol/sm2.htm) for spaced based repetition.

## Installation

LibSpacey uses cmake to handle building and compilation.

1.) Build Dependencies w/ Conan

```
mkdir build

cd build 

conan install --file ../conanfile.txt --build gtest .

cd build
```

2.) Build app w/ cmake

```
cmake ..

make
```

3.) Run app

```
./bin/flashcardEngineApp
```

4.) (optional) Run tests

```
./bin/run_tests
```

## Contributions

Contributions are welcome! Feel free to submit a pull request.

### License

MIT -- full license file included in this repo.
