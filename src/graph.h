#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
private:
  int num_nodes;
  std::vector<std::vector<int>> graph;
  std::unordered_map<int, std::unordered_map<int, int>> timeOfListChange;
};
