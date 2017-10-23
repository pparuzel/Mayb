#include "GameObject.hpp"

GameObject::GameObject(sf::Vector2f position, sf::Vector2i size, sf::Vector2i offset)
        : m_size(size), m_position(position),
          m_indicator{offset.x, offset.y, size.x, size.y} {}

sf::Vector2f GameObject::position() const {
    return m_position;
}
