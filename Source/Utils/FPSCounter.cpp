#include "Utils/FPSCounter.hpp"

#include "Utils/ResourceManager.hpp"

#include <iostream>

FPSCounter::FPSCounter()
    : currentFrames_(0)
    , fps_(0)
    , lastTick_(0)
    , font_(ResourceManager::load<sf::Font>(std_fs::path("Fonts") / "arial_bold.ttf"))
{
    text_.move(sf::Vector2f(10, 10));
    text_.setOutlineColor(sf::Color::Blue);
    text_.setOutlineThickness(2);
    text_.setFont(font_);
    text_.setCharacterSize(25);
}

void FPSCounter::update()
{
    constexpr float slotTime = .5f;
    ++currentFrames_;

    if (fpsTimer_.getElapsedTime().asSeconds() > slotTime)
    {
        fps_ = currentFrames_ / fpsTimer_.getElapsedTime().asSeconds();
        fpsTimer_.restart();
        currentFrames_ = 0;
    }
    lastTick_ = tickTimer_.restart().asSeconds();
}

void FPSCounter::draw(const RenderManager& renderer)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << fps_;
    text_.setString("FPS: " + ss.str());
    renderer.drawSFML(text_);
}

float FPSCounter::frametime() const
{
    return lastTick_;
}
