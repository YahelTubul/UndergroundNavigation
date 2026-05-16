//
// Created by Yahel Tubul on 29/04/2026.
//

#ifndef UNDERGROUNDNAVIGATION_GRAPH_H
#define UNDERGROUNDNAVIGATION_GRAPH_H
#include <vector>
#include <unordered_map>
#include "Node.h"
#include "Edge.h"

// This class represent the underground environment computationally
class Graph {
private:
        std::unordered_map<int, Node> nodesList; // save all nodes in the graph
        std::unordered_map<int, std::vector<Edge>> neighbourList; // save the neighbour of each node
public:
        void addNode(int id, std::string name, float x, float y, float z);
        void addEdge(int from, int dest, double weight);
        bool findNode(int id) const;
        std::vector<Edge> getNeighbours(int id) const;
        void block(int from, int dest);
        void unblock(int from, int dest);
        bool isBlocked(int from, int dest) const;
        const Node* getNode(int id) const;
        const std::unordered_map<int, Node>& getNodes() const;
        void printNodes() const;



};
#endif //UNDERGROUNDNAVIGATION_GRAPH_H