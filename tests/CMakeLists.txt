add_executable(test_my_function test_my_function.cpp)
target_link_libraries(test_my_function gtest gtest_main)
add_test(NAME test_my_function COMMAND test_my_function)
