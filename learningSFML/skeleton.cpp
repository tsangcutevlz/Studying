#include "./characters/skeleton.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void Skeleton::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/Skeleton/Texture/spritesheetone.png"))
    {
        int XIndex = 0;
        int YIndex = 2;

        std::cout << "Skeleton image loaded!" << std::endl;

        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1300, 650));
        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        sprite.scale(3, 3);
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
    {
        std::cout << "Skeleton image failed to loaded!" << std::endl;
    }
}

void Skeleton::Update(float deltaTime, sf::Event event)
{
    boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);
}