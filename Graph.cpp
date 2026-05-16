//
// Created by Yahel Tubul on 29/04/2026.
//
#include "Graph.h"
// add node in graph
void Graph::addNode(int id,std::string name, float x, float y, float z) {
    nodesList[id] = {id,name, x,y,z}; // allocate values in the node
}
// add edge from to sides to node in graph
void Graph::addEdge(int from, int dest, double weight) {
    //add edge to the first sides
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
// block edge between 2 nodes
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
// remove the block from specific edge
void Graph::unblock(int from, int dest) {
    // pass on each edge that get out from the node
    for (Edge& edge : neighbourList[from]) {
        if (edge.neighbour == dest)
            // sign the edge as unblock
            edge.isBlocked = false;
    }
    // pass on each edge that get out from the second side
    for (Edge& edge : neighbourList[dest]) {
        if (edge.neighbour == from)
            // sign the edge as unblock
            edge.isBlocked = false;
    }
}
// this function check if edge is blocked
bool Graph::isBlocked(int from, int dest) const {
    auto it = neighbourList.find(dest);
    // if not found node, the edge is blocked
    if (it == neighbourList.end())
        return true;
    // found the edge
    for (const Edge& edge : it->second) {
        if (edge.neighbour == from)
            return edge.isBlocked;
    }
    // if there is no edge , its blocked
    return true;
}
// return pointer to node
const Node* Graph::getNode(int id) const {
    auto it = nodesList.find(id);
    if (it == nodesList.end())
        return nullptr;
    return &it->second;
}
// return the nodes in the graph
const std::unordered_map<int, Node>& Graph::getNodes() const {
    return nodesList;
}





