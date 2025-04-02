#include "graph.h"

#include "utils.h"

namespace duck {

Graph::Graph(int n) : graph(n), num_nodes(n) {}

Graph::Graph(const nlohmann::json& j)
    : graph(j["num_nodes"]), num_nodes(j["num_nodes"]) {
    for (const auto& edge : j["edges"]) {
        boost::add_edge(edge[0], edge[1], graph);
    }
}

void Graph::addEdge(int ii, int jj) { boost::add_edge(ii, jj, graph); }

void Graph::removeEdge(int ii, int jj) { boost::remove_edge(ii, jj, graph); }

bool Graph::isConnected() {
    std::vector<int> component(num_nodes);
    int num_components = boost::connected_components(graph, &component[0]);
    return num_components == 1;
}

void Graph::iterate() {}

int Graph::numOfEdges() { return boost::num_edges(graph); }

bool Graph::hasEdge(int ii, int jj) {
    return boost::edge(ii, jj, graph).second;
}

int Graph::shortestPath(int ii, int jj) {
    // TODO !!! This is not the best way to do this
    return 1;
}

nlohmann::json Graph::getJson() {
    typedef boost::graph_traits<boost::adjacency_matrix<boost::undirectedS>>::
        edge_iterator EdgeIterator;

    nlohmann::json j;
    j["num_nodes"] = num_nodes;
    std::pair<EdgeIterator, EdgeIterator> edgePair = boost::edges(graph);
    for (EdgeIterator ei = edgePair.first; ei != edgePair.second; ++ei) {
        j["edges"].push_back({source(*ei, graph), target(*ei, graph)});
    }
    return j;
}

}  // namespace duck