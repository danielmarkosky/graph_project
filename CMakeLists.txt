cmake_minimum_required(VERSION 3.15)
project(DuckDuck)

file(GLOB SRC_FILES "src/*.cpp")
list(REMOVE_ITEM SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")
file(GLOB TEST_FILES "tests/*.cpp")

find_package(GTest REQUIRED)
find_package(Boost REQUIRED)

set(PACKAGES boost::boost gtest::gtest)

add_executable(${PROJECT_NAME} ${SRC_FILES} "src/main.cpp")
target_link_libraries(${PROJECT_NAME} ${PACKAGES})

add_executable(${PROJECT_NAME}_units ${SRC_FILES} ${TEST_FILES})
target_link_libraries(${PROJECT_NAME}_units ${PACKAGES})

add_executable(${PROJECT_NAME}_sandbox ${SRC_FILES} "sandbox/sandbox_main.cpp")
target_link_libraries(${PROJECT_NAME}_sandbox ${PACKAGES})