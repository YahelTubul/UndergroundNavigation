//
// Created by Yahel Tubul on 29/04/2026.
//
#include "Graph.h"
// add node in graph
void Graph::addNode(int id, float x, float y, float z) {
    nodesList[id] = {id, x,y,z}; // allocate values in the node
}
// add edge from to sides to node in graph
void Graph::addEdge(int from, int dest, double weight) {
    //add edge to the first side
    neighbourList[from].push_back({dest, weight,false});
    //add edge to the second side
    neighbourList[dest].push_back({from, weight, false});
}
//check if there is node with same id
bool Graph::findNode(int id) const{
    return nodesList.find(id) != nodesList.end();
}







