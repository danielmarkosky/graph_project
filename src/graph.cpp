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
    nlohmann::json j;
    j["num_nodes"] = num_nodes;
    //    for (auto edge : boost::edges(graph)) {
    //        j["edges"].push_back({boost::source(edge, graph),
    //        boost::target(edge, graph)});
    //    }
    for (int ii = 0; ii < num_nodes; ii++) {  // TODO !!! This sucks, please fix
        for (int jj = ii + 1; jj < num_nodes; jj++) {
            if (hasEdge(ii, jj)) {
                j["edges"].push_back({ii, jj});
            }
        }
    }
    return j;
}

}  // namespace duck