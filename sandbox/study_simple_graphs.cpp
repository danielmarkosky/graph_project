#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <nlohmann/json.hpp>
#include <thread>
#include <unordered_map>
#include <vector>

#include "../src/simple_graph.h"
#include "../src/utils.h"

const int num_of_tries = std::pow(10, 6);
const int max_iterations = std::pow(10, 2);
const int num_nodes_start = 2;
const int num_nodes_end = 4;
const int num_nodes_increment = 1;
const std::vector<std::pair<double, double>> probabilities = {
    {0.3, 0.3}, {0.3, 0.5}, {0.3, 0.7}, {0.5, 0.3}, {0.5, 0.5},
    {0.5, 0.7}, {0.7, 0.3}, {0.7, 0.5}, {0.7, 0.7}};

std::unordered_map<std::string, std::unordered_map<int, double>>
    probabilities_numOfNodes_avNumOfIterations;

std::mutex map_mutex;

void perform_iterations(double p_add, double p_remove, int num_of_nodes) {
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<long> iterations(num_of_tries);
    for (int ii = 0; ii < num_of_tries; ii++) {
        duck::SimpleGraph graph(num_of_nodes, p_add, p_remove);
        int iter = 0;
        while (iter++ < max_iterations && graph.isConnected()) {
            graph.iterate();
        }
        iterations[ii] = iter;
    }
    double average_number_of_iterations =
        std::accumulate(iterations.begin(), iterations.end(), 0) /
        static_cast<double>(num_of_tries);
    {
        std::lock_guard<std::mutex> lock(map_mutex);
        probabilities_numOfNodes_avNumOfIterations
            [std::to_string(p_add) + "_" + std::to_string(p_remove)]
            [num_of_nodes] = average_number_of_iterations;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "p_add: " << p_add << ", p_remove: " << p_remove
              << ", num_of_nodes: " << num_of_nodes
              << ", average_iterations: " << average_number_of_iterations
              << ", duration: " << duration.count() << " s" << std::endl;
}

int main() {
    std::cout << "Starting the simulation..." << std::endl;

    std::vector<std::thread> threads;

    for (const auto& [p_add, p_remove] : probabilities) {
        for (int num_of_nodes = num_nodes_start; num_of_nodes <= num_nodes_end;
             num_of_nodes += num_nodes_increment) {
            threads.emplace_back(perform_iterations, p_add, p_remove,
                                 num_of_nodes);
        }
    }

    for (auto& thread : threads) {
        thread.join();
    }

    nlohmann::json results =
        duck::get_json_from_map(probabilities_numOfNodes_avNumOfIterations);

    duck::write_json_to_file(
        results, "results",
        "study_simple_graphs" + duck::get_unique_name() + ".json");
}
