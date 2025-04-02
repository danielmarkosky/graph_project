#include <boost/graph/adjacency_matrix.hpp>
#include <chrono>
#include <iostream>
#include <nlohmann/json.hpp>

#include "../src/simple_graph.h"
#include "../src/utils.h"

int main() {
    std::cout << "Duck Hello :> SANDBOX" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    duck::SimpleGraph graph(50);
    graph.getJson();
    //    int max_iterations = 100000;
    //    int iter = 0;
    //    while (iter++ < max_iterations and graph.isConnected()) {
    //        std::cout << "Number of edges: " << graph.numOfEdges() <<
    //        std::endl; graph.iterate();
    //    }
    //    if (iter == max_iterations + 1) {
    //        std::cout << "Graph is still connected after " << max_iterations
    //                  << " iterations." << std::endl;
    //    } else {
    //        std::cout << "Graph is not connected after " << iter << "
    //        iterations."
    //                  << std::endl;
    //    }
    //
    //    auto end = std::chrono::high_resolution_clock::now();
    //
    //    std::chrono::duration<double> elapsed = end - start;
    //    std::cout << "Elapsed time: " << elapsed.count() << " seconds" <<
    //    std::endl;
}