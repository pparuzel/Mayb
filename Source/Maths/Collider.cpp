#include "Collider.hpp"

Collider::Collider(Vector2& position, const Vector2& size)
        : m_position(position), m_size(size) {}

COLLISION_TYPE Collider::detectCollision(const Collider& c, Vector2 vel) {
    float left = m_position.x;
    float right = m_position.x + m_size.x;
    float top = m_position.y;
    float bottom = m_position.y + m_size.y;
    float cleft = c.m_position.x;
    float cright = c.m_position.x + c.m_size.x;
    float ctop = c.m_position.y;
    float cbottom = c.m_position.y + c.m_size.y;
    float dx = vel.x;
    float dy = vel.y;
    COLLISION_TYPE col_type = COLLISION_TYPE::NO_COLLISION;
    if (left + dx < cright && right + dx > cleft && top < cbottom && bottom > ctop)
        col_type = COLLISION_TYPE::VERTICAL;
    if (left < cright && right > cleft && top + dy < cbottom && bottom + dy > ctop) {
        if (col_type == COLLISION_TYPE::VERTICAL)
            col_type = COLLISION_TYPE::BOTH;
        else
            col_type = COLLISION_TYPE::HORIZONTAL;
    }

    return col_type;
}

Collider::Collider(const Collider& other)
        : m_position(other.m_position), m_size(other.m_size) {
}
