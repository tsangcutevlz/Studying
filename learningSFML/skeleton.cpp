#include "./characters/skeleton.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Skeleton::Skeleton() : health(100)
{
}
Skeleton::~Skeleton()
{
}

void Skeleton::ChangeHealth(int hp)
{
    health += hp;
    healthText.setString(std::to_string(health));
}

void Skeleton::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
    if (font.loadFromFile("Assets/Font/Arial.ttf"))
    {
        std::cout << "[Success] Arial.ttf font in Assets has loaded!" << std::endl;
        healthText.setFont(font);
        healthText.setString(std::to_string(health));
    }
    else
    {
        std::cout << "[Warning] Arial.ttf font in Assets hasn't loaded!" << std::endl;
    }

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
    if (health > 0)
    {
        boundingRectangle.setPosition(sprite.getPosition());
        healthText.setPosition(sprite.getPosition());
    }
}

void Skeleton::Draw(sf::RenderWindow &window)
{
    if (health > 0)
    {
        window.draw(sprite);
        window.draw(boundingRectangle);
        window.draw(healthText);
    }
}