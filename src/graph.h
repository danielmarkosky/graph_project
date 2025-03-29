#pragma once

#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graph_traits.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace duck {

class Graph {
    int num_nodes;
    boost::adjacency_matrix<boost::undirectedS> graph;

   public:
    Graph() = delete;
    Graph(int);
    void iterate();
    bool is_connected();
};

}  // namespace duck