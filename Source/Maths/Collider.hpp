#ifndef MAYBSFML_COLLIDER_HPP
#define MAYBSFML_COLLIDER_HPP


#include "Vector2.hpp"

class Collider {
    const Vector2& m_position;
    Vector2 m_size;
public:
    Collider(const Vector2& position, Vector2 size);

    void detectCollision(const Collider& collider);

    void resolveCollision(const Collider& );
};


#endif //MAYBSFML_COLLIDER_HPP
