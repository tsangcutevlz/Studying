#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
    sf::Texture texture;
    
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;
public:
    sf::Sprite sprite;

public:
    void Initialize();
    void Load();
    void Update(float deltaTime, sf::Event event);
    void Draw(sf::RenderWindow &window);
};