#pragma once

#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <iostream>
#include <vector>
#include <unordered_map>

namespace duck {

  class Graph {
  private:
    int num_nodes;
    boost::adjacency_matrix<boost::undirectedS> graph;
  public:
    Graph(int);
    bool is_connected();
  };

}