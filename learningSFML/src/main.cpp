#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

#include "./characters/player.h"
#include "./characters/skeleton.h"
#include "./characters/math.h"
#include "./characters/map.h"
#include "./characters/frameRate.h"
#include "./characters/mapLoader.h"

int main()
{












    // --------------------------------- INITIALIZE ------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::RenderWindow window(sf::VideoMode(1500, 1080), "RPG GAME", sf::Style::Default, settings);
    window.setFramerateLimit(240);
    // --------------------------------- INITIALIZE ------------------------------------
    sf::Text frameRateText; // Sprite
    sf::Font font; // Textures
    
    Map map;
    FrameRate frameRate;
    Skeleton skeleton;
    Player player;

    // --------------------------------- INITIALIZE ------------------------------------
    map.Initialize();
    frameRate.Initialize();
    player.Initialize();
    skeleton.Initialize();
    // --------------------------------- INITIALIZE  ------------------------------------
    // --------------------------------- LOAD  ------------------------------------
    map.Load("./Assets/Map/Map1.txt");
    frameRate.Load();
    player.Load();
    skeleton.Load();
    // --------------------------------- LOAD  ------------------------------------
    sf::Clock clock;
    sf::Time deltaTimeTimer;
    double deltaTime = 0;
    while (window.isOpen())
    {
        clock.restart();

        frameRate.Update(deltaTime);
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

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        player.Shoot(deltaTime, skeleton, mousePosition);

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

        window.clear(sf::Color::Red);
        map.Draw(window);
        player.Draw(window);
        skeleton.Draw(window);
        frameRate.Draw(window);
        window.display();
        // ------------------------------ Draw ----------------------------------
    
        deltaTimeTimer = clock.getElapsedTime();
        deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0f;
    }

    return 0;
}