#pragma once

#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graph_traits.hpp>
#include <functional>
#include <iostream>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <vector>

namespace duck {

class Graph {
   protected:
    boost::adjacency_matrix<boost::undirectedS> graph;
    int num_nodes;
    void addEdge(int, int);
    void removeEdge(int, int);

    typedef std::unordered_map<int,
                               std::unordered_map<int, std::function<bool()>>>
        RulesMap;

    std::vector<std::pair<int, int>> iterate(const std::function<bool()>&,
                                             const std::function<bool()>&);
    std::vector<std::pair<int, int>> iterate(const RulesMap&, const RulesMap&);

   public:
    Graph() = delete;
    Graph(int);
    Graph(const nlohmann::json&);
    int numOfNodes();
    int numOfEdges();
    virtual std::vector<std::pair<int, int>> iterate();
    bool isConnected();
    bool hasEdge(int, int);
    std::vector<int> shortestPaths(int);
    nlohmann::json getJson();
    virtual ~Graph() = default;
};

}  // namespace duck