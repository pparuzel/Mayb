#include "PlacerFunction.hpp"

#include "FunctionManager.hpp"

PlacerFunction::PlacerFunction(FunctionManager& fmref)
    : manager_(fmref)
    , indicator_({70, 70})
    , pinned_("", sf::Sprite())
{
    indicator_.setFillColor({100, 255, 100, 127});
    printf("PlacerFunction\n");
}

void PlacerFunction::render(const RenderManager& renderer)
{
    auto pos = pinned_.getPosition();
    pos.x -= static_cast<int>(pos.x) % 35;
    pos.y -= static_cast<int>(pos.y) % 35;
    if (pos.y < 140)
    {
        pos.y = 140;
    }
    indicator_.setPosition(sf::Vector2f(pos));
    renderer.drawSFML(indicator_);
    renderer.loadSprite(pinned_);
}

void PlacerFunction::mousePressed(int posx, int posy)
{
    auto button = manager_.detectButton(posx, posy);
    if (button != manager_.buttonsEnd())
    {
        pinned_ = *button;
        pinned_.setPosition({0.f, 140.f});
        return;
    }

    auto block = manager_.detectBlock(indicator_.getGlobalBounds());
    if (posy < 140 || block != manager_.blocksEnd())
    {
        return;
    }
    Button b(pinned_);
    posx -= posx % 35;
    posy -= posy % 35;
    b.setPosition(sf::Vector2f(posx, posy));
    manager_.addBlock(b);
}

void PlacerFunction::mouseMoved(int posx, int posy)
{
    pinned_.setPosition(sf::Vector2f(posx, posy));
}
