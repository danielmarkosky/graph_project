#include <gtest/gtest.h>

#include "../src/simple_graph.h"

TEST(SimpleGraphTest, Constructor) {
    duck::SimpleGraph graph(10);
    EXPECT_EQ(graph.numOfEdges(), 45);
    EXPECT_TRUE(graph.isConnected());
}