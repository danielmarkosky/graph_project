#include <gtest/gtest.h>
#include "../src/graph.h"

TEST(GraphTest, IsConnected) {
  duck::Graph graph(5);
  EXPECT_TRUE(graph.is_connected());
}

