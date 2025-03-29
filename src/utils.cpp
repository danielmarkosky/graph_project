#include "utils.h"

bool duck::chance_with_probability(double p) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen) < p;
}