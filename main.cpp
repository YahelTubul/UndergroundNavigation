#include <iostream>
#include "Graph.h"
#include "ConfigManager.h"
#include "Controller.h"
#include <GraphLoader.h>


int main() {
    Graph graph;
    //load the graph from exiting file
    bool graphLoaded =GraphLoader::LoadGraph("../data/graph.txt",graph);
    //check if loading file is failed
    if (!graphLoaded)
    {
        std::cout << "Graph loading failed!" << std::endl;
        return 1;
    }
    //load the kalman gain from exiting file
    double gain = ConfigManager::LoadGain("../config/settings.txt");
    std::cout << "loaded gain: "<< gain << std::endl;
    Controller controller(graph, gain);


    return 0;
}