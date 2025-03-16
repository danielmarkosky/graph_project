cmake_minimum_required(VERSION 3.15)
project(DuckDuck)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(duckduck src/main.cpp)
