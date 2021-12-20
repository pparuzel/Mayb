#include "GameObject.hpp"

GameObject::GameObject(sf::Vector2f position, sf::Vector2i size, sf::Vector2i offset)
    : size_(size)
    , position_(position)
    , indicator_{offset.x, offset.y, size.x, size.y}
{
}

sf::Vector2f GameObject::position() const
{
    return position_;
}
