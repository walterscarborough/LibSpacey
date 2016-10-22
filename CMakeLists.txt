# Project and General Cmake Setup
project(LibSpacey)
cmake_minimum_required(VERSION 2.8.7)

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

set(NON_MAIN_SOURCES ${SOURCES})
list(REMOVE_ITEM NON_MAIN_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(run_test ${NON_MAIN_SOURCES} ${TEST_SOURCES})
target_link_libraries(run_test ${CONAN_LIBS})
