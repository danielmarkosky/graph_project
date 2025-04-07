#include <gtest/gtest.h>

#include "../src/simple_graph.h"

TEST(SimpleGraphTest, Constructor) {
    duck::SimpleGraph graph(10);
    EXPECT_EQ(graph.numOfEdges(), 45);
    EXPECT_TRUE(graph.isConnected());
}

TEST(SimpleGraphTest, IterateProbZero) {
    duck::SimpleGraph graph(10, 0, 0);
    auto changed_edges = graph.iterate();
    EXPECT_EQ(changed_edges.size(), 0);
    EXPECT_TRUE(graph.isConnected());
    EXPECT_EQ(graph.numOfEdges(), 45);
}

TEST(SimpleGraphTest, IterateProbOne) {
    duck::SimpleGraph graph(10, 1, 1);
    auto changed_edges = graph.iterate();
    EXPECT_EQ(changed_edges.size(), 45);
    EXPECT_FALSE(graph.isConnected());
    EXPECT_EQ(graph.numOfEdges(), 0);
    auto changed_edges2 = graph.iterate();
    EXPECT_EQ(changed_edges2.size(), 45);
    EXPECT_TRUE(graph.isConnected());
    EXPECT_EQ(graph.numOfEdges(), 45);
}

TEST(SimpleGraphTest, IterateProbZeroOne) {
    duck::SimpleGraph graph(10, 0, 1);
    auto changed_edges = graph.iterate();
    EXPECT_EQ(changed_edges.size(), 45);
    EXPECT_FALSE(graph.isConnected());
    EXPECT_EQ(graph.numOfEdges(), 0);
    auto changed_edges2 = graph.iterate();
    EXPECT_EQ(changed_edges2.size(), 0);
    EXPECT_FALSE(graph.isConnected());
    EXPECT_EQ(graph.numOfEdges(), 0);
}