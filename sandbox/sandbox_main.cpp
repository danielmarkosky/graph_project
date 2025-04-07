#include <functional>
#include <iostream>
#include <thread>
#include <unordered_map>
#include <vector>

#include "../src/simple_graph.h"
#include "../src/utils.h"

int main() {
    duck::SimpleGraph graph(100, .3, .4);

    graph.iterate();
}
