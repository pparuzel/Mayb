#include "Collider.hpp"

Collider::Collider(sf::Vector2f& position, sf::Vector2i size)
        : m_position(position), m_size(size) {}

CollisionType Collider::detectCollision(const Collider& c, sf::Vector2f change) {
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
    CollisionType collType = CollisionType::NoCollision;
    if (l + dx < cr && r + dx > cl && t < cb && b > ct) {
        if (dx > 0.f) {
            m_position.x = cl - m_size.x;
        } else {
            m_position.x = cr;
        }
        collType = CollisionType::Vertical;
    }
    if (l < cr && r > cl && t + dy < cb && b + dy > ct) {
        if (dy > 0.f) {
            m_position.y = ct - m_size.y;
            collType = static_cast<CollisionType> ((int) collType + (int) CollisionType::HorizontalGround);
        } else {
            m_position.y = cb;
            collType = static_cast<CollisionType> ((int) collType + (int) CollisionType::Horizontal);
        }
    }

    return collType;
}

void Collider::setSize(sf::Vector2i size) {
    m_size.x = size.x;
    m_size.y = size.y;
}
