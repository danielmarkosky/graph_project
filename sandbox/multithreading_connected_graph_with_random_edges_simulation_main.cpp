#include <chrono>
#include <cmath>
#include <iostream>
#include <nlohmann/json.hpp>
#include <numeric>
#include <thread>
#include <unordered_map>
#include <vector>

#include "../src/simple_graph.h"
#include "../src/utils.h"

void perform_iterations(
    int num_of_nodes, int number_of_tries, int max_iterations,
    std::unordered_map<int, std::vector<int>>& num_of_nodes_to_iterations) {
    for (int ii = 0; ii < number_of_tries; ii++) {
        duck::SimpleGraph graph(num_of_nodes);
        int iter = 0;
        while (iter++ < max_iterations && graph.isConnected()) {
            graph.iterate();
        }
        num_of_nodes_to_iterations[num_of_nodes].push_back(iter);
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    nlohmann::json results;
    std::unordered_map<int, std::vector<int>> num_of_nodes_to_iterations;

    int max_iterations = 100000000;
    int tries_const = 10000000;
    int num_nodes_start = 2;
    int num_nodes_end = 20;
    int num_nodes_increment = 1;

    std::vector<std::thread> threads;

    for (int num_of_nodes = num_nodes_start; num_of_nodes <= num_nodes_end;
         num_of_nodes += num_nodes_increment) {
        int number_of_tries =
            static_cast<int>(std::max(1., static_cast<double>(tries_const) /
                                              std::pow(2, num_of_nodes - 2)));

        threads.emplace_back(perform_iterations, num_of_nodes, number_of_tries,
                             max_iterations,
                             std::ref(num_of_nodes_to_iterations));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    for (int num_of_nodes = num_nodes_start; num_of_nodes <= num_nodes_end;
         num_of_nodes += num_nodes_increment) {
        double average_number_of_iterations =
            std::accumulate(num_of_nodes_to_iterations[num_of_nodes].begin(),
                            num_of_nodes_to_iterations[num_of_nodes].end(), 0) /
            static_cast<double>(
                num_of_nodes_to_iterations[num_of_nodes].size());
        results[std::to_string(num_of_nodes)]["average_iterations"] =
            std::to_string(average_number_of_iterations);
        results[std::to_string(num_of_nodes)]["number_of_tries"] =
            std::to_string(num_of_nodes_to_iterations[num_of_nodes].size());
    }

    duck::write_json_to_file(
        results, "results",
        "multithreading_connected_graph_with_random_edges.json");

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
}