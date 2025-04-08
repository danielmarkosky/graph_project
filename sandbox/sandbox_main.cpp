#include <atomic>
#include <filesystem>
#include <functional>
#include <iostream>
#include <nlohmann/json.hpp>
#include <thread>
#include <unordered_map>
#include <vector>

#include "../src/simple_graph.h"
#include "../src/utils.h"

int main() {
    nlohmann::json j{1, 1};
    std::cout << j.dump() << std::endl;
}
