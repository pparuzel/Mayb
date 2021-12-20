#include "RemovalFunction.hpp"
#include "FunctionManager.hpp"
#include <iostream>

RemovalFunction::RemovalFunction(FunctionManager& fmref)
    : manager_(fmref)
    , indicator_({70, 70})
{
    indicator_.setFillColor({100, 255, 100, 127});
    lastMousePos_ = {35, 175};
    printf("RemovalFunction\n");
}

void RemovalFunction::render(const RenderManager& renderer)
{
    sf::FloatRect rect(
        {static_cast<float>(lastMousePos_.x - 5), static_cast<float>(lastMousePos_.y - 5)},
        {10, 10});
    auto it = manager_.detectBlock(rect);
    sf::Vector2f pos;
    if (it == manager_.blocksEnd())
    {
        pos.x = lastMousePos_.x - 35;
        pos.y = lastMousePos_.y - 35;
    }
    else
    {
        pos = it->getPosition();
    }
    if (pos.y < 140)
    {
        pos.y = 140;
    }
    indicator_.setPosition(sf::Vector2f(pos));
    renderer.drawSFML(indicator_);
}

void RemovalFunction::mousePressed(int posx, int posy)
{
    auto block = manager_.detectBlock(indicator_.getGlobalBounds());
    if (block != manager_.blocksEnd())
    {
        manager_.removeBlock(block);
    }
}

void RemovalFunction::mouseMoved(int posx, int posy)
{
    lastMousePos_ = {posx, posy};
}
