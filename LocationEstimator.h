//
// Created by Yahel Tubul on 03/05/2026.
//

#ifndef UNDERGROUNDNAVIGATION_LOCATIONESTIMATOR_H
#define UNDERGROUNDNAVIGATION_LOCATIONESTIMATOR_H
#include "Graph.h"
class LocationEstimator {
private:
    float estimatX = 0, estimatY = 0, estimatZ = 0, Kal_gain = 0;
public:
    //constructor that define how much influence has to measure
    LocationEstimator (double gain = 0.6);
    void initialize(const Graph& graph, int startNode);


};


#endif //UNDERGROUNDNAVIGATION_LOCATIONESTIMATOR_H
