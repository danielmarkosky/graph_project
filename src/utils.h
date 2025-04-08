#pragma once

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <random>
#include <string>
#include <unordered_map>
#include <sstream>

namespace duck {

bool chance_with_probability(double);

std::string get_unique_name();

nlohmann::json get_json_from_map(
    const std::unordered_map<std::string, std::unordered_map<int, double>>&);

void create_directory(const std::string& path);

void write_json_to_file(const nlohmann::json&, const std::string& path,
                        const std::string& filename);

}  // namespace duck
