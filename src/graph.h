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
   protected:
    boost::adjacency_matrix<boost::undirectedS> graph;
    int num_nodes;
    void addEdge(int, int);
    void removeEdge(int, int);

   public:
    Graph() = delete;
    Graph(int);
    int numOfEdges();
    virtual void iterate();
    bool isConnected();
    bool hasEdge(int, int);
    virtual ~Graph() = default;
};

}  // namespace duck