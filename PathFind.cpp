#include "PathFind.h"

#include <queue>
#include <vector>
#include <algorithm>
#include "Graph.h"
#include <unordered_set>
//
// Created by Yahel Tubul on 30/04/2026.
//
// calc the cost from a node to the destination, based on distance between nodes
double PathFind::herusitic(const Graph& graph, int from, int dest) {
    const Node* start = graph.getNode(from);
    const Node* destNode = graph.getNode(dest);
    if (!start || !destNode)
        return 0.0;
    double dis_x = destNode->x - start->x;
    double dis_y = destNode->y - start->y;
    double dis_z = destNode->z - start->z;
    return sqrt(dis_x * dis_x + dis_y * dis_y + dis_z * dis_z);
}
std::vector<int> PathFind::findPath(const Graph& graph, int start, int dest) {
    std::priority_queue<
        std::pair<double,int>,
        std::vector<std::pair<double,int>>,
        std::greater<>
        > pendingNodes;
    std::unordered_map<int, double> costStart;
    std::unordered_map<int, int> cameFrom;
    std::unordered_set<int> visited_nodes; // stores the processed nodes
    // initialize the start node
    costStart[start] = 0.0;
    pendingNodes.push({herusitic(graph,start,dest),start});
    while (!pendingNodes.empty()) {
        // get the node with the low cost
        int currNode = pendingNodes.top().second;
        pendingNodes.pop();
        if (!visited_nodes.count(currNode)) {
            visited_nodes.insert(currNode);
            //check if the current node is the destination
            if (currNode == dest) {
                //restore the navigation path from cameFrom map
                std::vector<int> path;
                int node = dest;
                while (node != start) {
                    path.push_back(node);
                    node = cameFrom[node];
                }
                path.push_back(start);
                reverse(path.begin(), path.end());
                return path;
            }
            // pass on the neighbours of the current node
            for (const Edge& edge : graph.getNeighbours(currNode)) {
                //skip on block edges
                if (!edge.isBlocked && !visited_nodes.count(edge.neighbour)) {
                    double newG = costStart[currNode] + edge.weight;
                    if (!costStart.count(edge.neighbour) || newG < costStart[edge.neighbour]) {
                        costStart[edge.neighbour] = newG;
                        cameFrom[edge.neighbour] = currNode;
                        // estimated the total cost to guide the search
                        double f = newG + herusitic(graph, edge.neighbour, dest);
                        pendingNodes.push({f, edge.neighbour});
                    }
                }
            }
        }
    }
    return {};
}