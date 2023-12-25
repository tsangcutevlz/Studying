#pragma once
#include <SFML/Graphics.hpp>
#include "mapData.h"
#include "mapLoader.h"
#include "tile.h"

class Map
{
private:
    sf::Texture tileSheetTexture;
    MapLoader mapLoader;

    MapData md;

    Tile *tiles;

    int totalTilesX;
    int totalTilesY;
    int totalTiles;
 

    sf::Sprite* mapSprites;

public : Map();
    ~Map();
    void Initialize();
    void Load(std::string filename);
    void Update(float deltaTime, sf::Event event);
    void Draw(sf::RenderWindow &window);
};