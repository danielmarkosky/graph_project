#include "simple_graph.h"

#include "utils.h"

duck::SimpleGraph::SimpleGraph(int n, double p_add, double p_remove)
    : Graph(n), probability_add(p_add), probability_remove(p_remove) {
    for (int ii = 0; ii < num_nodes; ii++) {
        for (int jj = ii + 1; jj < num_nodes; jj++) {
            this->addEdge(ii, jj);
        }
    }
}

std::vector<std::pair<int, int>> duck::SimpleGraph::iterate() {
    return this->Graph::iterate(
        [this]() {
            return duck::chance_with_probability(this->probability_add);
        },
        [this]() {
            return duck::chance_with_probability(this->probability_remove);
        });
}
