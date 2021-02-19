#include "Graph.hpp"

#include <iostream>
#include <set>
#include <list>

int main() {
    int testcases;
    std::cin >> testcases;

    while (testcases--) {
        size_t num_nodes, num_edges;
        std::cin >> num_nodes >> num_edges;

        // create a new graph
        Graph g(num_nodes);

        // add all edges to the graph
        for (int i = 0; i < num_edges; ++i) {
            size_t from, to;
            std::cin >> from >> to;
            g.addEdge(from, to, 6);
        }

        // get the starting node from which BFS will start
        size_t starting_node;
        std::cin >> starting_node;

        std::set<size_t> visited;
        std::list<size_t > queue;
        queue.emplace_back(starting_node);
        while (!queue.empty()) {
            size_t current_node = queue.front();
            queue.pop_front();

            for (size_t &neighbor : g.allNeighbors(current_node)) {
                if (visited.count(neighbor)) {
                    continue;
                }

                queue.emplace_back(neighbor);
            }
        }
    }

    return 0;
}
