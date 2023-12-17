#include "./characters/bullet.h"
#include "./characters/math.h"
#include <iostream>

Bullet::Bullet() : speed(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::SetDirection()
{
}
void Bullet::Initialize(const sf::Vector2f &position, const sf::Vector2f &target, float speed)
{
    this->speed = speed;
    rectangleShape.setSize(sf::Vector2f(100, 50));
    rectangleShape.setPosition(position);
    direction = Math::NormalizeVector(target - position);
}
void Bullet::Update(float deltaTime)
{
    rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow &window)
{
    window.draw(rectangleShape);
}
