#include "Block.hpp"

Block::Block(const sf::Texture& tiles, sf::Vector2f position, sf::Vector2i size, sf::Vector2i offset)
        : GameObject(position, size, offset), m_bounds(m_position, size),  m_sprite() {

    m_sprite.setTexture(tiles);
    m_sprite.setTextureRect(m_indicator);
    m_sprite.setPosition(position);
}

Collider Block::AABBox() const {
    return m_bounds;
}

const sf::Sprite& Block::sprite() const {
    return m_sprite;
}
