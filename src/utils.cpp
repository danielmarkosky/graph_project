#include "utils.h"

bool duck::chance_with_probability(double p) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen) < p;
}

std::string duck::get_unique_name() {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                      now.time_since_epoch()) %
                  1000;

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&now_time_t), "%Y%m%d%H%M%S")
        << now_ms.count();
    return oss.str();
}

nlohmann::json duck::get_json_from_map(
    const std::unordered_map<std::string, std::unordered_map<int, double>>&
        map) {
    nlohmann::json j;
    for (const auto& outer_pair : map) {
        const std::string& outer_key = outer_pair.first;
        const std::unordered_map<int, double>& inner_map = outer_pair.second;

        for (const auto& inner_pair : inner_map) {
            int inner_key = inner_pair.first;
            double value = inner_pair.second;
            j[outer_key][std::to_string(inner_key)] = value;
        }
    }
    return j;
}

nlohmann::json duck::get_json_from_vector(
    const std::vector<std::pair<int, int>>& vector) {
    nlohmann::json j;
    for (const auto& pair : vector) {
        j.push_back({{pair.first, pair.second}});
    }
    return j;
}

void duck::create_directory(const std::string& path) {
    std::filesystem::create_directory(path);
}

void duck::write_json_to_file(const nlohmann::json& j, const std::string& path,
                              const std::string& file_name) {
    std::ofstream file(path + "/" + file_name);
    if (file.is_open()) {
        file << j.dump();
        file.close();
    } else {
        std::cerr << "Error opening file: " << path + "/" + file_name
                  << std::endl;
    }
}