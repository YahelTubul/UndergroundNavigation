//
// Created by Yahel Tubul on 02/05/2026.
//
#include <iostream>
#include <vector>
#include "Graph.h"
#include "PathFind.h"

void printPath(const std::vector<int>& path) {
    if (path.empty()) {
        std::cout << "No path found" << std::endl;
        return;
    }

    std::cout << "Path: ";
    for (int node : path) {
        std::cout << node;
        if (node != path.back()) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

int main() {
    Graph graph;

    // יצירת צמתים
    for (int i = 1; i <= 9; i++) {
        graph.addNode(i, 0, 0, 0);
    }

    // שורות
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 3, 2);

    graph.addEdge(4, 5, 3);
    graph.addEdge(5, 6, 2);

    graph.addEdge(7, 8, 1);
    graph.addEdge(8, 9, 2);

    // עמודות
    graph.addEdge(1, 4, 4);
    graph.addEdge(4, 7, 3);

    graph.addEdge(2, 5, 3);
    graph.addEdge(5, 8, 2);

    graph.addEdge(3, 6, 2);
    graph.addEdge(6, 9, 3);

    graph.block(2, 3);
    graph.block(5, 6);

    PathFind pathFinder;

    std::vector<int> path = pathFinder.findPath(graph, 1, 9);

    printPath(path);

    return 0;
}