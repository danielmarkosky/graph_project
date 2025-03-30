#pragma once

#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graph_traits.hpp>
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

   public:
    Graph() = delete;
    Graph(int);
    Graph(const nlohmann::json&);
    int numOfEdges();
    virtual void iterate();
    bool isConnected();
    bool hasEdge(int, int);
    int shortestPath(int, int);
    nlohmann::json getJson();
    virtual ~Graph() = default;
};

}  // namespace duck