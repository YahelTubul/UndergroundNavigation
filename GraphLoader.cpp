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


}
