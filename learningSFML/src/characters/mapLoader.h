#pragma once
#include <iostream>
#include "mapData.h"


class MapLoader
{
private:
public:
    MapLoader();
    ~MapLoader();
    // void Save(std::string filename);
    void Load(std::string filename, MapData& mapdata);

};