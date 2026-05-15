//
// Created by Yahel Tubul on 04/05/2026.
//

#include <iostream>
#include <ostream>

#include "Controller.h"
#define KALMAN_UPDATOR 3

Controller::Controller(Graph &graph) : graph(graph),location(0.6) {
}

void Controller::navigation(int start, int dest) {
    std::vector<int> pathFind = path.findPath(graph, start, dest);
    // check if there is path to navigate
    if (pathFind.empty()) {
        std::cout << "No path found" << std::endl;
    }
    std::cout << "Calculate path: ";
    for (int node : pathFind) {
        std::cout << node << " ";
    }
    // initialize the start location
    location.initialize(graph, start);
    for (int node : pathFind) {
        std::cout << "\nMeasured node: " << node << std::endl;
        for (int i = 0; i < KALMAN_UPDATOR; i++) {
            int estimatedNode = location.update(graph, node);

            std::cout << "Estimated closes node: "
                      << estimatedNode << std::endl;
        }
    }
    std::cout << "\nDestination reached." << std::endl;
}