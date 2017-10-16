#ifndef MAYBSFML_COLLIDER_HPP
#define MAYBSFML_COLLIDER_HPP


#include "Vector2.hpp"

class Collider {
    const Vector2& bodyPosition;
    const Vector2& bodySize;
public:
    Collider(const Vector2& position_ref, const Vector2& size_ref);
};


#endif //MAYBSFML_COLLIDER_HPP
