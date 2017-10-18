#include "Collider.hpp"

Collider::Collider(const Vector2& position, Vector2 size)
        : m_position(position), m_size(size) {}

void Collider::detectCollision(const Collider& c) {
    float X1 = m_position.x;
    float X2 = m_position.x + m_size.x;
    float Y1 = m_position.y;
    float Y2 = m_position.y + m_size.y;
    float cX1 = c.m_position.x;
    float cX2 = c.m_position.x + m_size.x;
    float cY1 = c.m_position.y;
    float cY2 = c.m_position.y + m_size.y;
    if (X1 < cX2 && X2 > cX1 && Y1 > cY2 && Y2 < cY1) {
        resolveCollision(c);
    }
}

void Collider::resolveCollision(const Collider& c) {

}
