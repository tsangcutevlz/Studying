#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "skeleton.h"
#include "bullet.h"

class Player
{
private:
    sf::Texture texture;

    std::vector<Bullet> bullets;

    float maxFireRate; 
    float fireRateTimer;

    float playerSpeed ;

    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;

public:
    sf::Sprite sprite;

public:
    Player();
    ~Player();
    void Initialize();
    void Load();
    void Update(float deltaTime, sf::Event event);
    void Shoot(float deltaTime, Skeleton &skeleton, sf::Vector2f mousePosition);
    void Draw(sf::RenderWindow &window);
};