#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
    sf::Texture texture;
    sf::Font font;
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;
    sf::Text healthText;
public:
    int health;
    sf::Sprite sprite;

public:
    Skeleton();
    ~Skeleton();

    void ChangeHealth(int hp);

    void Initialize();
    void Load();
    void Update(float deltaTime, sf::Event event);
    void Draw(sf::RenderWindow &window);
};