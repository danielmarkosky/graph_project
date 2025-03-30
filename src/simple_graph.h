#pragma once

#include "graph.h"

namespace duck {

class SimpleGraph : public Graph {
   public:
    SimpleGraph(int);
    void iterate() override;
};

}  // namespace duck