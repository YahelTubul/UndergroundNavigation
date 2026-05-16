//
// Created by Yahel Tubul on 15/05/2026.
//
#include "ConfigManager.h"

#include <fstream>
#include <iostream>

double ConfigManager::LoadGain(const std::string& filePath)
{
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        std::cout << "Failed to open config file!" << std::endl;
        return 1.0;
    }

    std::string line;

    while (std::getline(file, line))
    {
        size_t equalPos = line.find('=');

        if (equalPos != std::string::npos)
        {
            std::string key = line.substr(0, equalPos);
            std::string value = line.substr(equalPos + 1);

            if (key == "gain")
            {
                return std::stod(value);
            }
        }
    }

    return 1.0;
}