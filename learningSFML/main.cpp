#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector;

    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;
}

int main()
{

    // --------------------------------- INITIALIZE ------------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG GAME", sf::Style::Default, settings);

    // --------------------------------- INITIALIZE ------------------------------------

    std::vector<sf::RectangleShape> bullets;

    // sf::RectangleShape bullet(sf::Vector2f(50, 25));
    float bulletSpeed = 0.5f;

    // --------------------------------- LOAD ------------------------------------

    // --------------------------------- Skeleton ------------------------------------
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;

    if (skeletonTexture.loadFromFile("Assets/Skeleton/Texture/spritesheetone.png"))
    {
        int XIndex = 0;
        int YIndex = 2;

        std::cout << "Skeleton image loaded!" << std::endl;

        skeletonSprite.setTexture(skeletonTexture);
        skeletonSprite.setPosition(sf::Vector2f(1600, 800));
        skeletonSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        skeletonSprite.scale(2, 2);
    }
    else
    {
        std::cout << "Skeleton image failed to loaded!" << std::endl;
    }
    // --------------------------------- Skeleton ------------------------------------

    // --------------------------------- Player ------------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    if (playerTexture.loadFromFile("Assets/Player/Texture/spritesheetone.png"))
    {
        int XIndex = 0;
        int YIndex = 0;
        std::cout << "Player image loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        playerSprite.setPosition(sf::Vector2f(100, 100));
        playerSprite.scale(2, 2);
    }
    else
    {
        std::cout << "Player image failed to loaded!" << std::endl;
    }
    // --------------------------------- Player ------------------------------------

    // --------------------------------- Calculate direction to the bullet ------------------------------------
    // sf::Vector2f direction = skeletonSprite.getPosition() - bullet.getPosition();

    // direction = NormalizeVector(direction);
    // --------------------------------- Calculate direction to the bullet ------------------------------------

    // --------------------------------- LOAD ------------------------------------

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // ------------------------------ Update ----------------------------------
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
            {
                sf::Vector2f currentPosition = playerSprite.getPosition();
                playerSprite.setPosition(currentPosition + sf::Vector2f(0, -25));
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
            {
                sf::Vector2f currentPosition = playerSprite.getPosition();
                playerSprite.setPosition(currentPosition + sf::Vector2f(-25, 0));
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
            {
                sf::Vector2f currentPosition = playerSprite.getPosition();
                playerSprite.setPosition(currentPosition + sf::Vector2f(0, 25));
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
            {
                sf::Vector2f currentPosition = playerSprite.getPosition();
                playerSprite.setPosition(currentPosition + sf::Vector2f(25, 0));
            }
            // ------------------------------ Update ----------------------------------
        }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        // {
        //     sf::Vector2f currentPosition = playerSprite.getPosition();
        //     playerSprite.setPosition(currentPosition + sf::Vector2f(0, -10));
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        // {
        //     sf::Vector2f currentPosition = playerSprite.getPosition();
        //     playerSprite.setPosition(currentPosition + sf::Vector2f(-10, 0));
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        // {
        //     sf::Vector2f currentPosition = playerSprite.getPosition();
        //     playerSprite.setPosition(currentPosition + sf::Vector2f(0, 10));
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        // {
        //     sf::Vector2f currentPosition = playerSprite.getPosition();
        //     playerSprite.setPosition(currentPosition + sf::Vector2f(10, 0));
        // }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sf::RectangleShape newBullet(sf::Vector2f(50, 25));
            bullets.push_back(newBullet);
            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition());
        }

        for (int i = 0; i < bullets.size(); i++)
        {
            sf::Vector2f bulletDirection;
            bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
            bulletDirection = NormalizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }

        window.clear(sf::Color::Black);
        for (int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }

        window.draw(skeletonSprite);
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}