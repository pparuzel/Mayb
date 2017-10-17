#ifndef MAYBSFML_COLLIDER_HPP
#define MAYBSFML_COLLIDER_HPP


#include "Vector2.hpp"

class Collider {
    Vector2 m_position;
    Vector2 m_size;
public:
    Collider(Vector2 position, Vector2 size);

    void detectCollision() const;

    void resolveCollision() const;
};


#endif //MAYBSFML_COLLIDER_HPP
