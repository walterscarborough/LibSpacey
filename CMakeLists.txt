# Project and General Cmake Setup
project(LibSpacey)
cmake_minimum_required(VERSION 3.6)

# Conan Setup
include(build/conanbuildinfo.cmake)
conan_basic_setup()

# Compiler Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Source Files for App
include_directories(src)
file(GLOB SOURCES "src/*.cpp")
add_executable(flashcardEngineApp ${SOURCES})

# Source Files for Tests
include_directories(test)
file(GLOB TEST_SOURCES "test/*.cpp")
add_executable(run_test ${TEST_SOURCES})

target_link_libraries(run_test ${CONAN_LIBS})
