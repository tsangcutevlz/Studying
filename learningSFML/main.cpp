#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#include "./characters/player.h"
#include "./characters/skeleton.h"
#include "./characters/math.h"

int main()
{

    // --------------------------------- INITIALIZE ------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG GAME", sf::Style::Default, settings);
    window.setFramerateLimit(240);
    // --------------------------------- INITIALIZE ------------------------------------
    Skeleton skeleton;
    Player player;
    // --------------------------------- INITIALIZE & LOAD PLAYER, SKELETON ------------------------------------

    player.Initialize();
    skeleton.Initialize();
    player.Load();
    skeleton.Load();

    // --------------------------------- INITIALIZE & LOAD PLAYER, SKELETON ------------------------------------
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();
        // ------------------------------ Update ----------------------------------

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            player.Update(deltaTime, event);
            skeleton.Update(deltaTime, event);
        }

        player.Shoot(deltaTime, skeleton);
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

        // ------------------------------ Update ----------------------------------


        // ------------------------------ Draw ----------------------------------

        window.clear(sf::Color::Black);
        player.Draw(window);
        skeleton.Draw(window);

        window.display();

        // ------------------------------ Draw ----------------------------------
    }

    return 0;
}