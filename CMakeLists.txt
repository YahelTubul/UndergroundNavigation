cmake_minimum_required(VERSION 4.0)
project(UndergroundNavigation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(UndergroundNavigation
        Graph.cpp
        Graph.h
        Node.h
        Edge.h
        PathFind.h
        PathFind.cpp
        main.cpp
        LocationEstimator.h
        LocationEstimator.cpp
        Controller.h
        Controller.cpp
        ConfigManager.h
        ConfigManager.cpp
        GraphLoader.h)
