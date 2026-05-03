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
    // find the node follow the id
    const Node* startNode = graph.getNode(startId);
    // check that get valid node id
    if (startNode != nullptr) {
        estimatX = startNode->x;
        estimatY = startNode->y;
        estimatZ = startNode->z;
    }
}

int LocationEstimator::update(const Graph &graph, int measuredId) {
    // extract the measure node from the graph
    const Node* measureNode = graph.getNode(measuredId);
}