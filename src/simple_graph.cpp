#include "simple_graph.h"

#include "utils.h"

duck::SimpleGraph::SimpleGraph(int n) : Graph(n) {
    for (int ii = 0; ii < num_nodes; ii++) {
        for (int jj = ii + 1; jj < num_nodes; jj++) {
            boost::add_edge(ii, jj, graph);
        }
    }
}

void duck::SimpleGraph::iterate() {
    std::unordered_map<int, std::unordered_map<int, int>> edges_after_iteration;
    for (int ii = 0; ii < num_nodes; ii++) {
        for (int jj = ii + 1; jj < num_nodes; jj++) {
            if (duck::chance_with_probability(0.5)) {
                edges_after_iteration[ii][jj] = 1;
            } else {
                edges_after_iteration[ii][jj] = 0;
            }
        }
    }
    for (int ii = 0; ii < num_nodes; ii++) {
        for (int jj = ii + 1; jj < num_nodes; jj++) {
            if (hasEdge(ii, jj) and edges_after_iteration[ii][jj] == 0) {
                removeEdge(ii, jj);
            }
            if (!hasEdge(ii, jj) and edges_after_iteration[ii][jj] == 1) {
                addEdge(ii, jj);
            }
        }
    }
}
