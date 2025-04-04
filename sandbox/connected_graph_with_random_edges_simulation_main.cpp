#include <chrono>
#include <cmath>
#include <iostream>
#include <nlohmann/json.hpp>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "../src/simple_graph.h"
#include "../src/utils.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    nlohmann::json results;
    std::unordered_map<int, std::vector<int>> num_of_nodes_to_iterations;

    int max_iterations = 10000000;
    int tries_const = 10000000;
    int num_nodes_start = 2;
    int num_nodes_end = 15;
    int num_nodes_increment = 1;

    for (int num_of_nodes = num_nodes_start; num_of_nodes <= num_nodes_end;
         num_of_nodes += num_nodes_increment) {
        auto start_for_number = std::chrono::high_resolution_clock::now();

        // Too much casting? probably...
        int number_of_tries =
            static_cast<int>(std::max(1., static_cast<double>(tries_const) /
                                              std::pow(2, num_of_nodes - 2)));

        std::cout << "Number of nodes: " << num_of_nodes << std::endl;
        std::cout << "Number of tries: " << number_of_tries << std::endl;

        for (int ii = 0; ii < number_of_tries; ii++) {
            duck::SimpleGraph graph(num_of_nodes);
            int iter = 0;
            while (iter++ < max_iterations and graph.isConnected()) {
                graph.iterate();
            }

            num_of_nodes_to_iterations[num_of_nodes].push_back(iter);
        }

        double average_number_of_iterations =
            std::accumulate(num_of_nodes_to_iterations[num_of_nodes].begin(),
                            num_of_nodes_to_iterations[num_of_nodes].end(), 0) /
            static_cast<double>(number_of_tries);
        std::cout << "Average number of iterations: "
                  << average_number_of_iterations << std::endl;

        auto end_for_number = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_for_number =
            end_for_number - start_for_number;
        std::cout << "Elapsed time for number of nodes " << num_of_nodes << ": "
                  << elapsed_for_number.count() << " seconds" << std::endl;
        std::cout << std::endl;

        results[std::to_string(num_of_nodes)]["average_iterations"] =
            std::to_string(average_number_of_iterations);
        results[std::to_string(num_of_nodes)]["number_of_tries"] =
            std::to_string(number_of_tries);

        //                TODO Uncomment this if you want to see the iterations
        //                for each try
        //                results[std::to_string(num_of_nodes)]["iterations"] =
        //                    nlohmann::json::array();
        //                for (int ii = 0; ii < number_of_tries; ii++) {
        //                    results[std::to_string(num_of_nodes)]["iterations"].push_back(
        //                        num_of_nodes_to_iterations[num_of_nodes][ii]);
        //                }
    }

    duck::write_json_to_file(results, "results",
                             "connected_graph_with_random_edges.json");

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
}