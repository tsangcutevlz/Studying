#pragma once
#include "map.h"
#include <iostream>


class MapLoader
{
private:
public:
    MapLoader();
    ~MapLoader();
    // void Save(std::string filename);
    Mapdata* Load(std::string filename);

};