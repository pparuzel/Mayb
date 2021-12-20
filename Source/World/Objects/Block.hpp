#ifndef MAYBSFML_BLOCK_HPP
#define MAYBSFML_BLOCK_HPP

#include "../../Maths/Collider.hpp"
#include "GameObject.hpp"

class Block : public GameObject
{
    Collider bounds_;
    sf::Sprite sprite_;

public:
    Block(const sf::Texture& tiles,
          sf::Vector2f position,
          sf::Vector2i size,
          sf::Vector2i offset = {0, 0});

    Collider AABBox() const;

    const sf::Sprite& sprite() const;
};

#endif  // MAYBSFML_BLOCK_HPP
