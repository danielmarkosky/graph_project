#include "graph.h"

#include "utils.h"

duck::Graph::Graph(int n) : graph(n), num_nodes(n) {}

duck::Graph::Graph(const nlohmann::json& j)
    : graph(j["num_nodes"]), num_nodes(j["num_nodes"]) {
    for (const auto& edge : j["edges"]) {
        boost::add_edge(edge[0], edge[1], graph);
    }
}

// TODO Error handling
void duck::Graph::addEdge(int ii, int jj) { boost::add_edge(ii, jj, graph); }

// TODO Error handling
void duck::Graph::removeEdge(int ii, int jj) {
    boost::remove_edge(ii, jj, graph);
}

bool duck::Graph::isConnected() {
    std::vector<int> component(num_nodes);
    int num_components = boost::connected_components(graph, &component[0]);
    return num_components == 1;
}

std::vector<std::pair<int, int>> duck::Graph::iterate() { return {}; }

std::vector<std::pair<int, int>> duck::Graph::iterate(
    const std::function<bool()>& rule_to_add,
    const std::function<bool()>& rule_to_remove) {
    std::vector<std::pair<int, int>> change_edges;
    for (int ii = 0; ii < this->num_nodes; ii++) {
        for (int jj = ii + 1; jj < this->num_nodes; jj++) {
            if ((this->hasEdge(ii, jj) and rule_to_remove()) or
                (!this->hasEdge(ii, jj) and rule_to_add())) {
                change_edges.push_back({ii, jj});
            }
        }
    }
    for (const auto& edge : change_edges) {
        if (this->hasEdge(edge.first, edge.second)) {
            this->removeEdge(edge.first, edge.second);
        } else {
            this->addEdge(edge.first, edge.second);
        }
    }
    return change_edges;
}

std::vector<std::pair<int, int>> duck::Graph::iterate(
    const RulesMap& rules_to_add, const RulesMap& rules_to_remove) {
    std::vector<std::pair<int, int>> change_edges;
    for (int ii = 0; ii < this->num_nodes; ii++) {
        for (int jj = ii + 1; jj < this->num_nodes; jj++) {
            if ((this->hasEdge(ii, jj) and rules_to_remove.at(ii).at(jj)()) or
                (!this->hasEdge(ii, jj) and rules_to_add.at(ii).at(jj)())) {
                change_edges.push_back({ii, jj});
            }
        }
    }
    for (const auto& edge : change_edges) {
        if (this->hasEdge(edge.first, edge.second)) {
            this->removeEdge(edge.first, edge.second);
        } else {
            this->addEdge(edge.first, edge.second);
        }
    }
    return change_edges;
}

int duck::Graph::numOfNodes() { return num_nodes; }

int duck::Graph::numOfEdges() { return boost::num_edges(graph); }

bool duck::Graph::hasEdge(int ii, int jj) {
    return boost::edge(ii, jj, graph).second;
}

std::vector<int> duck::Graph::shortestPaths(int node) {
    // TODO !!! This is not the best way to do this
    return {};
}

nlohmann::json duck::Graph::getJson() {
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
