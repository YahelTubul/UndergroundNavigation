//
// Created by Yahel Tubul on 16/05/2026.
//
#include "GraphLoader.h"

#include <fstream>
#include <sstream>
#include <iostream>

bool GraphLoader::LoadGraph(const std::string& filePath, Graph& graph) {
    //open the file
    std::ifstream file(filePath);
    // check if the file is opened
    if (!file.is_open())
    {
        std::cout << "failed to open graph file!" << std::endl;
        return false;
    }
    std::string line;
    // read the file
    while (std::getline(file, line)) {
        //conver the line into stream for parsing
        std::stringstream ss(line);
        std::string type;
        // read the first word in the line
        ss >> type;
        if (type == "NODE")
        {
            int id;
            std::string name;
            double x;
            double y;
            double z;
            //example to line: NODE 1 Home 0 0 0
            ss >> id >> name >> x >> y >> z;
            // add the node into the graph
            graph.addNode(id, name, x, y, z);
        }
        else if (type == "EDGE")
        {
            int from,to;
            double weight;
            // example line: EDGE 1 2 5
            ss >> from >> to >> weight;
            // add weight connection between 2 nodes
            graph.addEdge(from, to, weight);
        }
        else if (type == "BLOCK")
        {
            int from,to;
            // example line: BLOCK 3 8
            ss >> from >> to;
            // mark the edge as block
            graph.block(from, to);
        }
    }
    file.close();
    return true;
}
