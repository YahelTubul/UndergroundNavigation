//
// Created by Yahel Tubul on 03/05/2026.
//
#include "LocationEstimator.h"

LocationEstimator::LocationEstimator(double gain) {
    Kal_gain = gain;
    estimatX = 0;
    estimatY = 0;
    estimatZ = 0;
}

void LocationEstimator::initialize(const Graph &graph, int startId) {
    const Node* startNode = graph.getNode(startId);
    if (startNode != nullptr) {
        estimatX = startNode->x;
        estimatY = startNode->y;
        estimatZ = startNode->z;
    }
}
