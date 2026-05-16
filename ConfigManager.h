//
// Created by Yahel Tubul on 15/05/2026.
//

#ifndef UNDERGROUNDNAVIGATION_CONFIGMANAGER_H
#define UNDERGROUNDNAVIGATION_CONFIGMANAGER_H
#include <string>
class ConfigManager
{
public:
    static double LoadGain(const std::string& filePath);
};

#endif //UNDERGROUNDNAVIGATION_CONFIGMANAGER_H