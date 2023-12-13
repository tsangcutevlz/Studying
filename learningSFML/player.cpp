#include <iostream>
#include "./characters/player.h"
#include "./characters/math.h"

void Player::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(1);

    size = sf::Vector2i(64, 64);
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Texture/spritesheetone.png"))
    {
        int XIndex = 0;
        int YIndex = 0;
        std::cout << "Player image loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
        sprite.setPosition(sf::Vector2f(0, 0));
        sprite.scale(3, 3);
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
    {
        std::cout << "Player image failed to loaded!" << std::endl;
    }
}

void Player::Update(float deltaTime, sf::Event event)
{
    float bulletSpeed = 0.5f;

    sf::Vector2f currentPosition = sprite.getPosition();
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
    {
        sprite.setPosition(currentPosition + sf::Vector2f(0, -25) * playerSpeed * deltaTime);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
    {
        sprite.setPosition(currentPosition + sf::Vector2f(-25, 0) * playerSpeed * deltaTime);
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
    {
        sprite.setPosition(currentPosition + sf::Vector2f(0, 25) * playerSpeed * deltaTime);
    }   
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
    {
        sprite.setPosition(currentPosition + sf::Vector2f(25, 0) * playerSpeed * deltaTime);
    }
}

void Player::Shoot(float deltaTime, Skeleton &skeleton)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        sf::RectangleShape newBullet(sf::Vector2f(50, 25));
        bullets.push_back(newBullet);
        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
    }

    for (int i = 0; i < bullets.size(); i++)
    {
        sf::Vector2f bulletDirection;
        bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::NormalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
    }

    boundingRectangle.setPosition(sprite.getPosition());

    if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
    {
        std::cout << "there's collision\n";
    }
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    for (int i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
    window.draw(boundingRectangle);
}