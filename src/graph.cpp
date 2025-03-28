#include "graph.h"

namespace duck {

  Graph::Graph(int n) : num_nodes(n), graph(n) {
    // Initialize the graph with n nodes and addes every edge
    // between every pair of nodes
    for (int ii = 0; ii < n; ii++) {
      for (int jj = ii + 1; jj < n; jj++) {
        boost::add_edge(ii, jj, graph);
      }
    }
  }

  bool Graph::is_connected() {
    std::vector<int> component(num_nodes);
    int num_components = boost::connected_components(graph, &component[0]);
    return num_components == 1;
  }

}