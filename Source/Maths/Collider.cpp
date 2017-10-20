#include "Collider.hpp"

Collider::Collider(Vector2& position, const Vector2& size)
        : m_position(position), m_size(size) {}

COLLISION_TYPE Collider::detectCollision(const Collider& c, Vector2 change) {
    float l = m_position.x;
    float r = m_position.x + m_size.x;
    float t = m_position.y;
    float b = m_position.y + m_size.y;
    float cl = c.m_position.x;
    float cr = c.m_position.x + c.m_size.x;
    float ct = c.m_position.y;
    float cb = c.m_position.y + c.m_size.y;
    float dx = change.x;
    float dy = change.y;
    COLLISION_TYPE collType = NO_COLLISION;
    if (l + dx < cr && r + dx > cl && t < cb && b > ct) {
        if (dx > 0.f) {
            m_position.x = cl - m_size.x;
        } else {
            m_position.x = cr;
        }
        collType = static_cast<COLLISION_TYPE> (collType + VERTICAL);
    }
    if (l < cr && r > cl && t + dy < cb && b + dy > ct) {
        if (dy > 0.f) {
            m_position.y = ct - m_size.y;
            collType = static_cast<COLLISION_TYPE> (collType + HORIZONTAL_GROUND);
        } else {
            m_position.y = cb;
            collType = static_cast<COLLISION_TYPE> (collType + HORIZONTAL);
        }
    }

    return collType;
}

Collider::Collider(const Collider& other)
        : m_position(other.m_position), m_size(other.m_size) {
}
