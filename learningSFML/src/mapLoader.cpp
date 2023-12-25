#include "./characters/mapLoader.h"
#include "./characters/mapData.h"
#include <fstream>
#include <string>
MapLoader::MapLoader()
{
}
MapLoader::~MapLoader()
{
}

// void MapLoader::Save(std::string filename)
// {
//     std::ofstream file;
//     file.open(filename);
//     file << "map 1 is opening....." << std::endl;
//     file << "1,1,1,25,27,30";
//     file.close();
// }

Mapdata MapLoader::Load(std::string filename)
{
    MapData mapdata;

    std::string line;
    std::ifstream file(filename);

    bool mapExist = false;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            if (!mapExist)
            {
                if (line == "[Map]")
                {
                    mapExist = true;
                    continue;
                }
                else
                {
                    std::cout << "map file is not valid!" << std::endl;
                    break;
                }
            }
            if (mapExist)
            {
                int count = line.find('=');
                std::string variable = line.substr(0, count);
                std::string value = line.substr(count + 1, line.length() - count);

                // std::cout << variable  << std::endl;
                // std::cout << value << std::endl;
                try
                {
                    if (variable == "version")
                    {
                        mapdata.version = value;
                    }
                    else if (variable == "tilesheet")
                    {
                        mapdata.tilesheet = value;
                    }
                    else if (variable == "name")
                    {
                        mapdata.name = value;
                    }
                    else if (variable == "scale-x")
                    {
                        mapdata.scaleX = std::stoi(value);
                    }
                    else if (variable == "scale-y")
                    {
                        mapdata.scaleY = std::stoi(value);
                    }
                    else if (variable == "tile-height")
                    {
                        mapdata.tileHeight = std::stoi(value);
                    }
                    else if (variable == "tile-width")
                    {
                        mapdata.tileWidth = std::stoi(value);
                    }
                    else if (variable == "dataLength")
                    {
                        mapdata.dataLength = std::stoi(value);
                    }
                    else if (variable == "data")
                    {
                        mapdata.data = new int[mapdata.dataLength];

                        int offset = 0;
                        int i = 0;
                        while (true)
                        {
                            int count = value.find(',', offset);
                            std::string mapIndex = value.substr(offset, count - offset);
                            if (mapIndex == ";")
                            {
                                break;
                            }
                            mapdata.data[i] = std::stoi(mapIndex);

                            // std::cout << mapIndex << std::endl;
                            offset = count + 2;
                            i++;
                        }
                    }
                }
                catch (const std::exception &e)
                {
                    std::cout << "i dont know. life happened! " << std::endl;
                }
            }
        }
        std::cout << mapdata.version << std::endl;
        std::cout << mapdata.tilesheet << std::endl;
        std::cout << mapdata.name << std::endl;
        std::cout << mapdata.scaleX << std::endl;
        std::cout << mapdata.scaleY << std::endl;
        std::cout << mapdata.tileHeight << std::endl;
        std::cout << mapdata.tileWidth << std::endl;
        std::cout << mapdata.dataLength << std::endl;
        std::cout << std::endl;
        for (int i = 0; i < mapdata.dataLength; i++)
        {
            std::cout << mapdata.data[i] << std::endl;
        }

        file.close();
    }
    else
    {
        std::cout << "file is unable to open " << std::endl;
    }
}
