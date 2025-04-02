#include <gtest/gtest.h>

#include "../src/graph.h"

TEST(GraphTest, Constructor) {
    duck::Graph graph(10);
    EXPECT_EQ(graph.numOfEdges(), 0);
}

TEST(GraphTest, IsConnected) {
    duck::Graph graph(5);
    EXPECT_FALSE(graph.isConnected());
}

TEST(GraphTest, JsonConstructor) {
    nlohmann::json j = {{"num_nodes", 5},
                        {"edges", {{0, 1}, {1, 2}, {2, 3}, {3, 4}}}};
    duck::Graph graph(j);
    EXPECT_EQ(graph.numOfEdges(), 4);
    EXPECT_TRUE(graph.hasEdge(0, 1));
    EXPECT_TRUE(graph.hasEdge(1, 2));
    EXPECT_TRUE(graph.hasEdge(2, 3));
    EXPECT_TRUE(graph.hasEdge(3, 4));
}

TEST(GraphTest, ShortestPath) {
    //        nlohmann::json j = {{"num_nodes", 5},
    //                            {"edges", {{0, 1}, {1, 2}, {2, 3}, {3, 4}}}};
    //        duck::Graph graph(j);
    //        EXPECT_EQ(graph.shortestPath(0, 1), 1);
    //        EXPECT_EQ(graph.shortestPath(0, 4), 4);
}

TEST(GraphTest, GetJson) {
    nlohmann::json j = {{"num_nodes", 5},
                        {"edges", {{0, 1}, {1, 2}, {2, 3}, {3, 4}}}};
    duck::Graph graph(j);
    nlohmann::json j2 = graph.getJson();
    EXPECT_EQ(j2["num_nodes"], 5);
    EXPECT_EQ(j2["edges"].size(), 4);
}
