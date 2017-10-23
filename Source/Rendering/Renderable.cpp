#include "Renderable.hpp"

Renderable::Renderable(sf::Vector2i offset, sf::Vector2i size)
        : m_indicator(offset, size) {}

const sf::Sprite& Renderable::sprite() const {
    return m_sprite;
}
