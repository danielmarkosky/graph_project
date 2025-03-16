cmake_minimum_required(VERSION 3.15)
project(MyCppProject)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(myapp src/main.cpp src/my_function.cpp)

# Add Google Test
enable_testing()
add_subdirectory(tests)
