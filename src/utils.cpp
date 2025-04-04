#include "utils.h"

bool duck::chance_with_probability(double p) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen) < p;
}

void duck::write_json_to_file(const nlohmann::json& j, const std::string& path,
                              const std::string& file_name) {
    std::ofstream file(path + "/" + file_name);
    if (file.is_open()) {
        file << j.dump(4);  // Pretty print with 4 spaces
        file.close();
    } else {
        std::cerr << "Error opening file: " << path + "/" + file_name
                  << std::endl;
    }
}