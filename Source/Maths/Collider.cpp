#include "Collider.hpp"

Collider::Collider(sf::Vector2f& position, sf::Vector2i bodySize,
                   sf::Vector2i horizMargin, sf::Vector2i vertMargin)
        : m_position(position), m_bodySize(bodySize),
          m_hMargin(horizMargin), m_vMargin(vertMargin) {}

CollisionType Collider::detectCollision(const Collider& c, sf::Vector2f change) {
    float l = m_position.x - m_hMargin.x;
    float r = m_position.x + m_bodySize.x + m_hMargin.y;
    float t = m_position.y - m_vMargin.x;
    float b = m_position.y + m_bodySize.y + m_vMargin.y;
    float cl = c.m_position.x;
    float cr = c.m_position.x + c.m_bodySize.x;
    float ct = c.m_position.y;
    float cb = c.m_position.y + c.m_bodySize.y;
    float dx = change.x;
    float dy = change.y;
    CollisionType collType = CollisionType::NoCollision;
    if (l + dx < cr && r + dx > cl && t < cb && b > ct) {
        if (dx > 0.f) {
            m_position.x = cl - m_bodySize.x - m_hMargin.y;
        } else {
            m_position.x = cr + m_hMargin.x;
        }
        collType = CollisionType::Vertical;
    }
    if (l < cr && r > cl && t + dy < cb && b + dy > ct) {
        if (dy > 0.f) {
            m_position.y = ct - m_bodySize.y - m_vMargin.y;
            collType = static_cast<CollisionType> ((int) collType + (int) CollisionType::HorizontalGround);
        } else {
            m_position.y = cb + m_vMargin.x;
            collType = static_cast<CollisionType> ((int) collType + (int) CollisionType::Horizontal);
        }
    }

    return collType;
}

void Collider::setMargin(int top, int bottom, int left, int right) {
    m_vMargin = {top, bottom};
    m_hMargin = {left, right};
}
