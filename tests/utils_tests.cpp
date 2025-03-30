#include <gtest/gtest.h>

#include "../src/utils.h"

TEST(UtilsTest, ChanceWithProbability) {
    double p = 0.5;
    int trials = 10000;
    int successes = 0;
    for (int ii = 0; ii < trials; ii++) {
        if (duck::chance_with_probability(p)) {
            successes++;
        }
    }
    EXPECT_NEAR(successes / static_cast<double>(trials), p, 0.05);
}