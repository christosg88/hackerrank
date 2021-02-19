#ifndef BREADTH_FIRST_SEARCH_SHORTEST_REACH_GRAPH_HPP
#define BREADTH_FIRST_SEARCH_SHORTEST_REACH_GRAPH_HPP

#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    size_t num_nodes;
    std::vector<std::vector<int>> adjacency_matrix;

public:
    explicit Graph(size_t num_nodes) : num_nodes(num_nodes), adjacency_matrix(num_nodes, std::vector<int>(num_nodes)) {
    }

    void addEdge(size_t from, size_t to, int weight) {
        if (!adjacency_matrix[from][to]) {
            adjacency_matrix[from][to] = weight;
        }
        else {
            adjacency_matrix[from][to] = std::min(weight, adjacency_matrix[from][to]);
        }
    }

    int getWight(size_t from, size_t to) {
        return adjacency_matrix[from][to];
    }

    bool edgeExists(size_t from, size_t to) {
        return adjacency_matrix[from][to] != 0;
    }

    std::list<size_t> allNeighbors(size_t from) {
        std::list<size_t> neighbors;
        for (size_t to = 0; to < num_nodes; ++to) {
            if (adjacency_matrix[from][to]) {
                neighbors.emplace_back(to);
            }
        }

        return neighbors;
    }
};

#endif
