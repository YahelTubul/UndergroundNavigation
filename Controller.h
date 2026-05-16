//
// Created by Yahel Tubul on 04/05/2026.
//

#ifndef UNDERGROUNDNAVIGATION_CONTROLLER_H
#define UNDERGROUNDNAVIGATION_CONTROLLER_H
#include "Graph.h"
#include "PathFind.h"
#include "LocationEstimator.h"

class Controller {
private:
    Graph& graph;
    LocationEstimator location;
    PathFind path;
public:
    Controller(Graph& graph, double gain);
    void navigation(int start, int dest);


};
#endif //UNDERGROUNDNAVIGATION_CONTROLLER_H