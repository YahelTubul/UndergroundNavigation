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
    // check if the node exists
    if (measureNode == nullptr) {
        return -1;
    }
    // update the estimate location follow the formula: estimated = estimated + K * (measured - estimated)
    estimatX = estimatX + Kal_gain * (measureNode->x - estimatX);
    estimatY = estimatY + Kal_gain * (measureNode->y - estimatY);
    estimatZ = estimatZ + Kal_gain * (measureNode->z - estimatZ);

    return getClose(graph);
}

int LocationEstimator::getClose(const Graph &graph) const {
    // save the smallest distance
    double closeDis = std::numeric_limits<double>::max();
    int closeNode = 0;
    for (const auto& pair : graph.getNodes()) {
        const Node& node = pair.second;
        //calculate the difference in axes
        float dx = node.x - estimatX;
        float dy = node.y - estimatY;
        float dz = node.z - estimatZ;
        //calculate the distance
        double dist = dx*dx + dy*dy + dz*dz;
        // update the best distance
        if (dist < closeDis) {
            closeDis = dist;
            closeNode = node.id;
        }
    }
    return closeNode;
}
