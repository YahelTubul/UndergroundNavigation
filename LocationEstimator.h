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
    LocationEstimator(double gain);
    // define the start position of the estimated location
    void initialize(const Graph& graph, int startId);
    // update the user estimated location and returns the node id closest to the new location.
    int update(const Graph& graph, int measuredId);
    // find and return the node id close to the current estimated coordinates
    int getClose(const Graph& graph) const;

};


#endif //UNDERGROUNDNAVIGATION_LOCATIONESTIMATOR_H
