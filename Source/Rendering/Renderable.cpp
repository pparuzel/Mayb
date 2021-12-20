#include "Renderable.hpp"

Renderable::Renderable(sf::Vector2i offset, sf::Vector2i size)
    : indicator_(offset, size)
{
}

const sf::Sprite& Renderable::sprite() const
{
    return sprite_;
}
