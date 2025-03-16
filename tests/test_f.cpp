#include <gtest/gtest.h>
#include "my_function.h"

TEST(MyFunctionTest, HandlesPositiveInput) {
    EXPECT_EQ(my_function(2, 3), 5);
    EXPECT_EQ(my_function(10, 20), 30);
}

TEST(MyFunctionTest, HandlesNegativeInput) {
    EXPECT_EQ(my_function(-2, -3), -5);
    EXPECT_EQ(my_function(-10, 20), 10);
}
