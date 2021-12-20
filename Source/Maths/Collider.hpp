#ifndef MAYBSFML_COLLIDER_HPP
#define MAYBSFML_COLLIDER_HPP

#include "SFML/Graphics.hpp"

enum class CollisionType
{
    NoCollision = 0,
    Vertical = 1,
    Horizontal = 2,
    Both = 3,
    HorizontalGround = 4,
    BothGround = 5
};

class Collider
{
    sf::Vector2f& position_;
    sf::Vector2i bodySize_;
    sf::Vector2i hMargin_;
    sf::Vector2i vMargin_;

public:
    Collider(sf::Vector2f& position,
             sf::Vector2i bodySize,
             sf::Vector2i horizMargin = {0, 0},
             sf::Vector2i vertMargin = {0, 0});

    CollisionType detectRectCollision(const Collider&, sf::Vector2f);

    void setMargin(int top, int bottom, int left, int right);
};

#endif  // MAYBSFML_COLLIDER_HPP
