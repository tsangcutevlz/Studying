#pragma once
#include <SFML/Graphics.hpp>
#include "tile.h"

class Map
{
private:
    sf::Texture tileSheetTexture;

    Tile *tiles;

    int tileWidth;
    int tileHeight;

    int totalTilesX;
    int totalTilesY;

    int totalTiles;


    static const int mapSize = 6;
    int mapWidth;
    int mapHeight;
    int mapNumbers[mapSize] = {
        1, 1, 1,
        25, 27, 30
        };

    sf::Sprite mapSprites[mapSize];

public : Map();
    ~Map();
    void Unload();
    void Initialize();
    void Load();
    void Update(float deltaTime, sf::Event event);
    void Draw(sf::RenderWindow &window);
};