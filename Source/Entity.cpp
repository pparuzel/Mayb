#include "Entity.hpp"

Entity::Entity(sf::Vector2i size, sf::Vector2f position, sf::Vector2f velocity, sf::Vector2i offset)
        : m_size(size), m_position(position), m_velocity(velocity),
          m_bounds(m_position, size), grounded(false),
          Renderable(offset, size) {
    m_sprite.setTextureRect(m_indicator);
    m_sprite.setPosition(position);
}

void Entity::resolveCollision(CollisionType collType) {
    if (collType == CollisionType::Vertical) {
        m_velocity.x = 0;
        grounded = false;
    } else if (collType == CollisionType::Horizontal || collType == CollisionType::HorizontalGround) {
        m_velocity.y = 0;
    } else if (collType == CollisionType::Both || collType == CollisionType::BothGround) {
        m_velocity = {0, 0};
        grounded = false;
    }
    if (collType == CollisionType::HorizontalGround || collType == CollisionType::BothGround) {
        grounded = true;
    }
}

const sf::Vector2f& Entity::velocity() const {
    return m_velocity;
}

Collider& Entity::AABBox() {
    return m_bounds;
}
