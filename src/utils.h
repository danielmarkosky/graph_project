#pragma once

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <random>

namespace duck {

bool chance_with_probability(double);

void write_json_to_file(const nlohmann::json&, const std::string&,
                        const std::string&);

}  // namespace duck