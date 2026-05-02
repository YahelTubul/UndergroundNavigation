#include "PathFind.h"

#include <queue>
#include <vector>

#include "Graph.h"
//
// Created by Yahel Tubul on 30/04/2026.
//
std::vector<int> PathFind::findPath(const Graph& graph, int start, int dest) {
    std::priority_queue<
        std::pair<double,int>,
        std::vector<std::pair<double,int>>,
        std::greater<>
        > pendingNodes;
    std::unordered_map<int, double> costStart;
    std::unordered_map<int, int> cameFrom;
    // initialize the start node
    costStart[start] = 0.0;
    pendingNodes.push({0.0,start});
    while (!pendingNodes.empty()) {

    }
}