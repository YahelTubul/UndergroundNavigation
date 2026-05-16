//
// Created by Yahel Tubul on 16/05/2026.
//
#include "Graph.h"

#ifndef UNDERGROUNDNAVIGATION_GRAPHLOADER_H
#define UNDERGROUNDNAVIGATION_GRAPHLOADER_H

class GraphLoader {
public:
    static bool LoadGraph(const std::string& filePath, Graph& graph);
};
#endif //UNDERGROUNDNAVIGATION_GRAPHLOADER_H
