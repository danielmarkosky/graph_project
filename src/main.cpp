#include <iostream>
#include "graph.h"

int main() {
  std::cout << "Duck Hello:>" << std::endl;

  duck::Graph graph(10);
  int max_iterations = 1000;
  int iter = 0;
  while (iter++ < max_iterations and graph.is_connected()) {
    graph.iterate();
  }
  if (iter == max_iterations + 1) {
    std::cout << "Graph is connected after " << max_iterations << " iterations." << std::endl;
  } else {
    std::cout << "Graph is not connected after " << iter << " iterations." << std::endl;
  }
}
