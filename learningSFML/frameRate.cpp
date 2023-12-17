#include "./characters/frameRate.h"
#include <iostream>


FrameRate::FrameRate() : timer(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
    if (font.loadFromFile("Assets/Font/Arial.ttf"))
    {
        std::cout << "[Success] Arial.ttf font in Assets has loaded!" << std::endl;
        frameRateText.setFont(font);
    }
    else
    {
        std::cout << "[Warning] Arial.ttf font in Assets hasn't loaded!" << std::endl;
    }
}

void FrameRate::Update(float deltaTime)
{
    timer += deltaTime;
    if (timer >= 250.0f)
    {
        float result = 1000.0f / deltaTime;
        std::string frameRateString = "FPS: " + std::to_string((int)result) +
                                      " frameTime: " + std::to_string((int)deltaTime);
        frameRateText.setString(frameRateString);
        timer = 0;
    }
}

void FrameRate::Draw(sf::RenderWindow &window)
{
    window.draw(frameRateText);
}