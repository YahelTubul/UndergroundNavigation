//
// Created by Yahel Tubul on 30/04/2026.
//

#ifndef UNDERGROUNDNAVIGATION_PATHFIND_H
#define UNDERGROUNDNAVIGATION_PATHFIND_H
#include <vector>
#include "Graph.h"

class PathFind {
public:
    static std::vector<int> findPath(const Graph& graph, int start, int dest);
private:
    static double herusitic(const Graph& graph, int start, int dest);
};
#endif //UNDERGROUNDNAVIGATION_PATHFIND_H