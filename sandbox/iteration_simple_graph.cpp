#include "../src/simple_graph.h"
#include "../src/utils.h"

#include <chrono>
#include <iostream>
#include <nlohmann/json.hpp>

int max_iterations = 1000;
int num_of_nodes = 1000;

nlohmann::json description = {
    {"Description",
     "Data from running iteration_simple_graph.cpp file. It can be used for "
     "like drawing graphs and watching how it looks, you know. Or not. "
     "Whatever :>"},
    {"max_iterations", max_iterations},
    {"num_of_nodes", num_of_nodes}};

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Starting the simulation..." << std::endl;

    std::string directory_path =
        "results/iteration_simple_graph" + duck::get_unique_name();
    duck::create_directory(directory_path);
    duck::write_json_to_file(description, directory_path, "description.json");

    duck::SimpleGraph graph(num_of_nodes, 0.5, 0.5);
    int iter = 0;

    while (iter++ < max_iterations and graph.isConnected()) {
        std::vector<std::pair<int,int>> changed_edges = std::move(graph.iterate());
        nlohmann::json j = duck::get_json_from_vector(changed_edges);
        duck::write_json_to_file(j, directory_path,
                                  std::to_string(iter) + ".json");
        std::cout << "Iteration " << iter << ": " << changed_edges.size()
                  << " edges changed." << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::seconds>(end - start);
    std::cout << "Simulation finished after " << iter
              << " iterations. Duration: " << duration.count() << " s"
              << std::endl;
}