#pragma once

#include "graph.h"

namespace duck {

class DependedIterationGraph : public duck::Graph {
   public:
    DependedIterationGraph(int n) : duck::Graph(n) {}
    void iterate() override;
};

}  // namespace duck