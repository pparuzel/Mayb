#include "Block.hpp"

Block::Block(const sf::Texture& tiles,
             sf::Vector2f position,
             sf::Vector2i size,
             sf::Vector2i offset)
    : GameObject(position, size, offset)
    , bounds_(position_, size)
{

    sprite_.setTexture(tiles);
    sprite_.setTextureRect(indicator_);
    sprite_.setPosition(position);
}

Collider Block::AABBox() const
{
    return bounds_;
}

const sf::Sprite& Block::sprite() const
{
    return sprite_;
}
