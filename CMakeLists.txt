cmake_minimum_required(VERSION 3.15)
project(DuckDuck)

find_package(GTest REQUIRED)

file(GLOB SRC_FILES "src/*.cpp")
list(REMOVE_ITEM SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")
file(GLOB TEST_FILES "tests/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES} "src/main.cpp")

add_executable(${PROJECT_NAME}_units ${SRC_FILES} ${TEST_FILES})
target_link_libraries(${PROJECT_NAME}_units gtest::gtest)
