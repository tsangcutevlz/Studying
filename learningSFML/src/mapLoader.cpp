#include "./characters/mapLoader.h"
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

void MapLoader::Load(std::string filename)
{
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
                std::string value = line.substr(count + 1, line.length() - count - 1);

            
                std::cout << variable  << std::endl;
                std::cout << value << std::endl;    
            }
        }

        file.close();
    }
    else
    {
        std::cout << "file is unable to open" << std::endl;
    }
}
