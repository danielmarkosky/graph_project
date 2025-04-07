#include <gtest/gtest.h>

#include <chrono>
#include <thread>

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
    // It does make me feel a little bit uncomfortable
    EXPECT_NEAR(successes / static_cast<double>(trials), p, 0.05);
}

TEST(UtilsTest, ChanceWithProbabilityZero) {
    double p = 0.0;
    int trials = 10000;
    int successes = 0;
    for (int ii = 0; ii < trials; ii++) {
        if (duck::chance_with_probability(p)) {
            successes++;
        }
    }
    EXPECT_EQ(successes, 0);
}

TEST(UtilsTest, ChanceWithProbabilityOne) {
    double p = 1.0;
    int trials = 10000;
    int successes = 0;
    for (int ii = 0; ii < trials; ii++) {
        if (duck::chance_with_probability(p)) {
            successes++;
        }
    }
    EXPECT_EQ(successes, trials);
}

TEST(UtilsTest, GetUniqueName) {
    std::string name1 = duck::get_unique_name();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::string name2 = duck::get_unique_name();
    EXPECT_NE(name1, name2);
}

TEST(UtilsTest, GetJsonFromMap) {
    std::unordered_map<std::string, std::unordered_map<int, double>> map = {
        {"key1", {{1, 1.1}, {2, 2.2}}}, {"key2", {{3, 3.3}, {4, 4.4}}}};

    nlohmann::json j = duck::get_json_from_map(map);

    EXPECT_EQ(j["key1"]["1"], 1.1);
    EXPECT_EQ(j["key1"]["2"], 2.2);
    EXPECT_EQ(j["key2"]["3"], 3.3);
    EXPECT_EQ(j["key2"]["4"], 4.4);
}
