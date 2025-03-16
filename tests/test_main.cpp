#include <gtest/gtest.h>
#include "../src/fun.h"

TEST(FunTest, SimpleTest) {
    EXPECT_EQ(fun(-1), 1);
    EXPECT_EQ(fun(10), 100);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}