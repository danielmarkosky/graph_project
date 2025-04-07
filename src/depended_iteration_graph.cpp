#include "depended_iteration_graph.h"

#include "utils.h"

// duck::DependedIterationGraph::DependedIterationGraph(int n) : Graph(n) {
//    for (int ii = 0; ii < num_nodes; ii++) {
//        for (int jj = ii + 1; jj < num_nodes; jj++) {
//            boost::add_edge(ii, jj, graph);
//        }
//    }
//}
//
// void duck::DependedIterationGraph::iterate() {
//    double probablityOfDissapiring = 0.25;
//    double connectionStrength = 2.5;
//    std::unordered_map<int, std::unordered_map<int, int>>
//    edges_after_iteration; for (int ii = 0; ii < num_nodes; ii++) {
//        for (int jj = ii + 1; jj < num_nodes; jj++) {
//            // TODO !!! refactoring needed I guess
//            double d = static_cast<double>(shortestPath(ii, jj));
//            double p = connectionStrength / (d * d);
//            if (duck::chance_with_probability(probablityOfDissapiring)) {
//                edges_after_iteration[ii][jj] = 1;
//            } else {
//                edges_after_iteration[ii][jj] = 0;
//            }
//        }
//    }
//    for (int ii = 0; ii < num_nodes; ii++) {
//        for (int jj = ii + 1; jj < num_nodes; jj++) {
//            if (hasEdge(ii, jj) and edges_after_iteration[ii][jj] == 0) {
//                removeEdge(ii, jj);
//            }
//            if (!hasEdge(ii, jj) and edges_after_iteration[ii][jj] == 1) {
//                addEdge(ii, jj);
//            }
//        }
//    }
//}
