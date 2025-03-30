#include "graph.h"

#include "utils.h"

namespace duck {

Graph::Graph(int n) : graph(n), num_nodes(n) {
    for (int ii = 0; ii < num_nodes; ii++) {
        for (int jj = ii + 1; jj < num_nodes; jj++) {
            boost::add_edge(ii, jj, graph);
        }
    }
}

void Graph::addEdge(int ii, int jj) { boost::add_edge(ii, jj, graph); }

void Graph::removeEdge(int ii, int jj) { boost::remove_edge(ii, jj, graph); }

bool Graph::isConnected() {
    std::vector<int> component(num_nodes);
    int num_components = boost::connected_components(graph, &component[0]);
    return num_components == 1;
}

int Graph::numOfEdges() { return boost::num_edges(graph); }

bool Graph::hasEdge(int ii, int jj) {
    return boost::edge(ii, jj, graph).second;
}

}  // namespace duck