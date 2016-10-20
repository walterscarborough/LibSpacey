cmake_minimum_required(VERSION 3.6)
project(LibSpacey)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(src)
file(GLOB SOURCES "src/*.cpp")

add_executable(flashcardEngineApp ${SOURCES})
