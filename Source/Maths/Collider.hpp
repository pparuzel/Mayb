#ifndef MAYBSFML_COLLIDER_HPP
#define MAYBSFML_COLLIDER_HPP


#include "Vector2.hpp"

enum COLLISION_TYPE {
    NO_COLLISION = 0,
    VERTICAL = 1,
    HORIZONTAL = 2,
    BOTH = HORIZONTAL + VERTICAL,
    HORIZONTAL_GROUND = 4,
    BOTH_GROUND = VERTICAL + HORIZONTAL_GROUND
};

class Collider {
    Vector2& m_position;
    const Vector2& m_size;
public:
    Collider(const Collider& );

    Collider(Vector2& position, const Vector2& size);

    COLLISION_TYPE detectCollision(const Collider& , Vector2 );
};


#endif //MAYBSFML_COLLIDER_HPP
