#include <iostream>
#include "./characters/map.h"
#include "./characters/tile.h"

Map::Map() : 
totalTilesX(0), totalTilesY(0),
totalTiles(0), tiles(nullptr) 
{
}
Map::~Map()
{

    delete[] tiles;
    delete[] mapSprites;
}

void Map::Initialize()
{
}
void Map::Load(std::string filename)
{
    mapLoader.Load("./Assets/Map/Map1.txt", md);
    // TODO: DELETE ME LATER PLEASE 
    mapSprites = new sf::Sprite[md.dataLength];
 
    if (tileSheetTexture.loadFromFile(md.tilesheet))
    {
        std::cout << "[Success] world has been loaded" << std::endl;

        totalTilesX = tileSheetTexture.getSize().x / md.tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / md.tileHeight;

        totalTiles = totalTilesX * totalTilesY;

        tiles = new Tile[totalTiles];

        for (int y = 0; y < totalTilesY; y++)
        {
            for (int x = 0; x < totalTilesX; x++)
            {
                int i = x + y * totalTilesX;
                tiles[i].id = i;
                tiles[i].position = sf::Vector2f(x * md.tileWidth, y * md.tileHeight);
            }
        }

        for (int y = 0; y < md.mapHeight; y++)
        {
            for (int x = 0; x < md.mapWidth; x++)
            {
                int i = x + y * md.mapWidth;
                int index = md.data[i];

                mapSprites[i].setTexture(tileSheetTexture);
                mapSprites[i].setTextureRect(sf::IntRect(
                    tiles[index].position.x, 
                    tiles[index].position.y, 
                    md.tileWidth, 
                    md.tileHeight));
                mapSprites[i].setScale(sf::Vector2f(4, 4));
                mapSprites[i].setPosition(sf::Vector2f(x * md.tileHeight * mapSprites[i].getScale().x, 100 + y * md.tileWidth * mapSprites[i].getScale().y));
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
    for (int i = 0; i < md.dataLength; i++)
    {
        window.draw(mapSprites[i]);
    }
}