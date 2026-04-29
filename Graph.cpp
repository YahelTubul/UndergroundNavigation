
//
// Created by Yahel Tubul on 29/04/2026.
//
#include "Graph.h"

void Graph::addNode(int id, float x, float y, float z) {
    nodesList[id] = {id, x,y,z}; // allocate values in the node
}


