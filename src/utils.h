#pragma once

#include <chrono>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <random>
#include <string>
#include <unordered_map>
#include <sstream>

namespace duck {

bool chance_with_probability(double);

std::string get_unique_name();  // Maybe for later

nlohmann::json get_json_from_map(
    const std::unordered_map<std::string, std::unordered_map<int, double>>&);

void write_json_to_file(const nlohmann::json&, const std::string&,
                        const std::string&);

}  // namespace duck
