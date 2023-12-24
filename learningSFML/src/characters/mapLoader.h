#pragma once
#include "map.h"
#include <iostream>


class MapLoader{
private:
public:
    MapLoader();
    ~MapLoader();
    // void Save(std::string filename);
    void Load(std::string filename);
};