#include "graph.h"
#include "utils.h"

namespace duck {

  Graph::Graph(int n) : num_nodes(n), graph(n) {
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

  void Graph::iterate() {
	std::unordered_map<int, std::unordered_map<int, int>> edges_after_iteration;
    for (int ii = 0; ii < num_nodes; ii++) {
	  for (int jj = ii+1; jj < num_nodes; jj++) {
        if (duck::chance_with_probability(0.5)) {
          edges_after_iteration[ii][jj] = 1;
        } else {
          edges_after_iteration[ii][jj] = 0;
        }
//		if (boost::edge(ii, jj, graph).second) {
//          edges_after_iteration[ii][jj] = 1;
//		} else {
//          edges_after_iteration[ii][jj] = 0;
//		}
	  }
	}
	for (int ii = 0; ii < num_nodes; ii++) {
      for (int jj = ii+1; jj < num_nodes; jj++) {
		if (boost::edge(ii, jj, graph).second and edges_after_iteration[ii][jj] == 0) {
          boost::remove_edge(ii, jj, graph);
        }
        if (!boost::edge(ii, jj, graph).second and edges_after_iteration[ii][jj] == 1) {
          boost::add_edge(ii, jj, graph);
        }
      }
    }
  }

}