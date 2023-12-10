#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME", sf::Style::Default, settings);
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Texture/spritesheetone.png"))
    {
        int XIndex = 0;
        int YIndex = 0;
        std::cout << "Player image loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        playerSprite.scale(4, 4);
    }
    else
    {
        std::cout << "Player image failed to loaded!" << std::endl;
    }
    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            std::cout << "pressed W";
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
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
        }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        // {
        //     std::cout << "pressed W";
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

        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}