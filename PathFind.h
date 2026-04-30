//
// Created by Yahel Tubul on 30/04/2026.
//

#ifndef UNDERGROUNDNAVIGATION_PATHFIND_H
#define UNDERGROUNDNAVIGATION_PATHFIND_H
#include <vector>
#include "Graph.h"

class PathFind {
public:
    std::vector<int> findPath(const Graph& graph, int start, int dest);
};
#endif //UNDERGROUNDNAVIGATION_PATHFIND_H