#pragma once

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
private:
  boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> graph;

};
