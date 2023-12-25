#pragma once
#include <string>

struct MapData
{
    int version;

    std::string tilesheet = "";
    std::string name = "";
    unsigned int tileWidth = 0;
    unsigned int tileHeight = 0;
    int scaleX = 0;
    int scaleY = 0;
    int dataLength = 0;
    int* data = nullptr;
};
