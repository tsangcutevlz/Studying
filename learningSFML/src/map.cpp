#include <iostream>
#include "./characters/map.h"
#include "./characters/tile.h"

Map::Map() : 
tileWidth(16), tileHeight(16), totalTilesX(0), totalTilesY(0),
totalTiles(0), mapWidth(3), mapHeight(2), tiles(nullptr) 
{
}
Map::~Map()
{
    Unload();
}

void Map::Unload()
{
    if (tiles != nullptr)
    {
        delete[] tiles;
        tiles = nullptr;
    }
}

void Map::Initialize()
{
}
void Map::Load()
{
    if (tileSheetTexture.loadFromFile("Assets/World/Prison/tilesheet.png"))
    {
        std::cout << "[Success] world has been loaded" << std::endl;

        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        totalTiles = totalTilesX * totalTilesY;

        tiles = new Tile[totalTiles];

        for (int y = 0; y < totalTilesY; y++)
        {
            for (int x = 0; x < totalTilesX; x++)
            {
                int i = x + y * totalTilesX;
                tiles[i].id = i;
                tiles[i].position = sf::Vector2f(x * tileWidth, y * tileHeight);
            }
        }

        for (int y = 0; y < mapHeight; y++)
        {
            for (int x = 0; x < mapWidth; x++)
            {
                int i = x + y * mapWidth;
                int index = mapNumbers[i];
                mapSprites[i].setTexture(tileSheetTexture);
                mapSprites[i].setTextureRect(sf::IntRect(
                    tiles[index].position.x, 
                    tiles[index].position.y, 
                    tileWidth, 
                    tileHeight));
                mapSprites[i].setScale(sf::Vector2f(4, 4));
                mapSprites[i].setPosition(sf::Vector2f(x * tileHeight * mapSprites[i].getScale().x, 100 + y * tileWidth * mapSprites[i].getScale().y));
            }
        }
    }
    else
    {
        std::cout << "[Warning] Arial.ttf font in Assets hasn't loaded!" << std::endl;
    }
}
void Map::Update(float deltaTime, sf::Event event)
{
}
void Map::Draw(sf::RenderWindow &window)
{
    for (int i = 0; i < mapSize; i++)
    {
        window.draw(mapSprites[i]);
    }
}