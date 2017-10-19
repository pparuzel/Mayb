#ifndef MAYBSFML_COLLIDER_HPP
#define MAYBSFML_COLLIDER_HPP


#include "Vector2.hpp"

enum class COLLISION_TYPE {
    NO_COLLISION = 0,
    HORIZONTAL = 1,
    VERTICAL = 2,
    BOTH = 3
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
