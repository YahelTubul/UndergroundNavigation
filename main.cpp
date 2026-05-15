#include <iostream>
#include "Graph.h"
#include "Controller.h"

int main() {
    Graph graph;

    // Nodes: id, x, y, z
    graph.addNode(1, 0, 0, 0);
    graph.addNode(2, 1, 0, 0);
    graph.addNode(3, 2, 0, 0);
    graph.addNode(4, 0, 1, 0);
    graph.addNode(5, 1, 1, 0);
    graph.addNode(6, 2, 1, 0);
    graph.addNode(7, 0, 2, 0);
    graph.addNode(8, 1, 2, 0);
    graph.addNode(9, 2, 2, 0);

    // Edges: from, to, weight
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 3, 2);

    graph.addEdge(1, 4, 4);
    graph.addEdge(2, 5, 3);
    graph.addEdge(3, 6, 2);

    graph.addEdge(4, 5, 3);
    graph.addEdge(5, 6, 2);

    graph.addEdge(4, 7, 3);
    graph.addEdge(5, 8, 2);
    graph.addEdge(6, 9, 3);

    graph.addEdge(7, 8, 1);
    graph.addEdge(8, 9, 2);

    // חסימות לדוגמה
    graph.block(2, 3);
    graph.block(5, 6);

    Controller controller(graph);

    int startNode = 1;
    int destinationNode = 9;

    controller.navigation(startNode, destinationNode);

    return 0;
}