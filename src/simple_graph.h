#pragma once

#include "graph.h"

namespace duck {

class SimpleGraph : public Graph {
   private:
    double probability_add;
    double probability_remove;

   public:
    SimpleGraph(int num_of_nodes, double p_add = 0.5, double p_remove = 0.5);
    std::vector<std::pair<int, int>> iterate() override;
};

}  // namespace duck