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
const int max_iterations = std::pow(10, 6);
const int num_nodes_start = 2;
const int num_nodes_end = 3;
const int num_nodes_increment = 1;
const std::vector<std::pair<double, double>> probabilities = {
    {0.1, 0.1}, {0.1, 0.2}, {0.1, 0.3}, {0.1, 0.4}, {0.1, 0.5}, {0.1, 0.6},
    {0.1, 0.7}, {0.1, 0.8}, {0.1, 0.9}, {0.2, 0.1}, {0.2, 0.2}, {0.2, 0.3},
    {0.2, 0.4}, {0.2, 0.5}, {0.2, 0.6}, {0.2, 0.7}, {0.2, 0.8}, {0.2, 0.9},
    {0.3, 0.1}, {0.3, 0.2}, {0.3, 0.3}, {0.3, 0.4}, {0.3, 0.5}, {0.3, 0.6},
    {0.3, 0.7}, {0.3, 0.8}, {0.3, 0.9}, {0.4, 0.1}, {0.4, 0.2}, {0.4, 0.3},
    {0.4, 0.4}, {0.4, 0.5}, {0.4, 0.6}, {0.4, 0.7}, {0.4, 0.8}, {0.4, 0.9},
    {0.5, 0.1}, {0.5, 0.2}, {0.5, 0.3}, {0.5, 0.4}, {0.5, 0.5}, {0.5, 0.6},
    {0.5, 0.7}, {0.5, 0.8}, {0.5, 0.9}, {0.6, 0.1}, {0.6, 0.2}, {0.6, 0.3},
    {0.6, 0.4}, {0.6, 0.5}, {0.6, 0.6}, {0.6, 0.7}, {0.6, 0.8}, {0.6, 0.9},
    {0.7, 0.1}, {0.7, 0.2}, {0.7, 0.3}, {0.7, 0.4}, {0.7, 0.5}, {0.7, 0.6},
    {0.7, 0.7}, {0.7, 0.8}, {0.7, 0.9}, {0.8, 0.1}, {0.8, 0.2}, {0.8, 0.3},
    {0.8, 0.4}, {0.8, 0.5}, {0.8, 0.6}, {0.8, 0.7}, {0.8, 0.8}, {0.8, 0.9},
    {0.9, 0.1}, {0.9, 0.2}, {0.9, 0.3}, {0.9, 0.4}, {0.9, 0.5}, {0.9, 0.6},
    {0.9, 0.7}, {0.9, 0.8}, {0.9, 0.9}};

nlohmann::json description = {
    {"Description",
     "Data from running study_simple_graph.cpp file. It aims at studying the "
     "average "
     "number of iterations needed for full graph with a given number of nodes "
     "to stop being connected. Iteration is done by adding and removing edges "
     "at random "
     "with given probabilities."},
    {"num_of_tries", num_of_tries},
    {"max_iterations", max_iterations},
    {"num_nodes_start", num_nodes_start},
    {"num_nodes_end", num_nodes_end},
    {"num_nodes_increment", num_nodes_increment},
    {"probabilities", probabilities}};

std::unordered_map<std::string, std::unordered_map<int, double>>
    probabilities_numOfNodes_avNumOfIterations;

std::mutex map_mutex;

std::atomic<int> file_counter(0);

void perform_iterations(double p_add, double p_remove, int num_of_nodes,
                        const std::string& directory_path) {
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

    nlohmann::json result = {
        {"p_add", p_add},
        {"p_remove", p_remove},
        {"num_of_nodes", num_of_nodes},
        {"average_iterations", average_number_of_iterations}};

    duck::write_json_to_file(result, directory_path,
                             std::to_string(file_counter++) + ".json");

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "p_add: " << p_add << ", p_remove: " << p_remove
              << ", num_of_nodes: " << num_of_nodes
              << ", average_iterations: " << average_number_of_iterations
              << ", duration: " << duration.count() << " s" << std::endl;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Starting the simulation..." << std::endl;

    std::string directory_path =
        "results/study_simple_graphs" + duck::get_unique_name();
    duck::create_directory(directory_path);
    duck::write_json_to_file(description, directory_path, "description.json");

    std::vector<std::thread> threads;

    for (const auto& [p_add, p_remove] : probabilities) {
        for (int num_of_nodes = num_nodes_start; num_of_nodes <= num_nodes_end;
             num_of_nodes += num_nodes_increment) {
            threads.emplace_back(perform_iterations, p_add, p_remove,
                                 num_of_nodes, directory_path);  // ~120s
        }
    }

    for (auto& thread : threads) {
        thread.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "Total duration: " << duration.count() << " s" << std::endl;
}
