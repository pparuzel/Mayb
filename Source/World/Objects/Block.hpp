#ifndef MAYBSFML_BLOCK_HPP
#define MAYBSFML_BLOCK_HPP


#include "GameObject.hpp"
#include "../../Maths/Collider.hpp"

class Block : public GameObject {
    Collider    m_bounds;
    sf::Sprite  m_sprite;
public:
    Block(const sf::Texture& tiles, sf::Vector2f position, sf::Vector2i size, sf::Vector2i offset={0, 0});

    Collider AABBox() const;

    const sf::Sprite& sprite() const;
};


#endif //MAYBSFML_BLOCK_HPP
