#include <iostream>
#include "graph.h"

int main() {
  std::cout << "Duck Hello:>" << std::endl;
  // Make a graph
  // start checking the shortest paths and connectivity
  // do till the graph is no longer connected
  duck::Graph graph(5);
  int iter = 0;
  while (iter++ < 10 and graph.is_connected()) {
    std::cout << "Graph is connected " << iter << std::endl;
  }
}
