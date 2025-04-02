#include <iostream>

#include "graph.h"
#include "simple_graph.h"

int main() {
    std::cout << "Duck Hello:>" << std::endl;

    duck::SimpleGraph graph(100);
    int max_iterations = 10000;
    int iter = 0;
    while (iter++ < max_iterations and graph.isConnected()) {
        std::cout << "Number of edges: " << graph.numOfEdges() << std::endl;
        graph.iterate();
    }
    if (iter == max_iterations + 1) {
        std::cout << "Graph is still connected after " << max_iterations
                  << " iterations." << std::endl;
    } else {
        std::cout << "Graph is not connected after " << iter << " iterations."
                  << std::endl;
    }
}
