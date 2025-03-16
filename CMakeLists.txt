cmake_minimum_required(VERSION 3.15)
project(DuckDuck)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} src/fun.cpp src/main.cpp)
target_link_libraries(${PROJECT_NAME} gtest::gtest)

add_executable(${PROJECT_NAME}_units src/fun.cpp tests/test_main.cpp)
target_link_libraries(${PROJECT_NAME}_units gtest::gtest)
