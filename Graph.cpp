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
// return the edges that get out from the nodes
std::vector<Edge>Graph::getNeighbours(int id) const {
    //search the node in the neighbour list
    auto it = neighbourList.find(id);
    // if not found return empty vector
    if (it == neighbourList.end())
        return {};
    //return the edges the get out from the node
    return it->second;
}

void Graph::block(int from, int dest) {
    // pass on each edge that get out from the node
    for (Edge& edge : neighbourList[from]) {
        if (edge.neighbour == dest)
            // sign the edge as blocked
            edge.isBlocked = true;
    }
    // pass on each edge that get out from the second side
    for (Edge& edge : neighbourList[dest]) {
        if (edge.neighbour == from)
            // sign the edge as blocked
            edge.isBlocked = true;
    }

}






