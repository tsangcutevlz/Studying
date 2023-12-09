#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Enemy
{
private:
public:
    int damage;
    int health;
    void Kill()
    {
        cout << "you are killed" << endl;
    }

    void Heal()
    {
        health += 10;
        cout << "you are Healed" << endl;
    }

    void Walk()
    {
        cout << "you walk" << endl;
    }
};

int main()
{
    // sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::RectangleShape recShape(sf::Vector2f(100, 200));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Green);
    recShape.setFillColor(sf::Color::Red);
    recShape.setPosition(sf::Vector2f(400, 400));
    recShape.setOutlineThickness(10);
    recShape.setOutlineColor(sf::Color::Green);

    sf::Vector2f origin(recShape.getSize().x / 2, recShape.getSize().y / 2);
    recShape.setOrigin(origin);

    recShape.setRotation(45);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Yellow);
        window.draw(shape);
        window.draw(recShape);
        window.display();
    }

    // float speed;
    // bool isAlive;
    // int hp;
    // Enemy goblin;
    // goblin.health = 100;
    // goblin.damage = 50;
    // goblin.Walk();

    // // cout << goblin.health << endl;
    // cout << "hello";

    return 0;
}
