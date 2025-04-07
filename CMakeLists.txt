cmake_minimum_required(VERSION 3.15)
project(DuckyDuck)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES "src/*.cpp")
list(REMOVE_ITEM SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")
file(GLOB TEST_FILES "tests/*.cpp")

find_package(GTest REQUIRED)
find_package(Boost REQUIRED)
find_package(nlohmann_json REQUIRED)

set(PACKAGES boost::boost gtest::gtest nlohmann_json::nlohmann_json)

add_executable(${PROJECT_NAME}_main ${SRC_FILES} "src/main.cpp")
target_link_libraries(${PROJECT_NAME}_main ${PACKAGES})

add_executable(${PROJECT_NAME}_unit_tests ${SRC_FILES} ${TEST_FILES})
target_link_libraries(${PROJECT_NAME}_unit_tests ${PACKAGES})

add_executable(${PROJECT_NAME}_sandbox ${SRC_FILES} "sandbox/sandbox_main.cpp")
target_link_libraries(${PROJECT_NAME}_sandbox ${PACKAGES})

# Executables for simulations of different kinds of graphs:

add_executable(${PROJECT_NAME}_study_simple_graphs ${SRC_FILES} "sandbox/study_simple_graphs.cpp")
target_link_libraries(${PROJECT_NAME}_study_simple_graphs ${PACKAGES})
