#include "Entity.hpp"

Entity::Entity(sf::Vector2i size, sf::Vector2f position, sf::Vector2i offset, const std::string& metaname)
        : m_size(size), m_position(position), m_velocity({0.f, 0.f}),
          m_bounds(m_position, size), grounded(false),
          Renderable(offset, size), Serializable(metaname) {
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

void Entity::writeObject() {
    std::ofstream f(filepath, f.binary);
    write(f, m_position);
    write(f, m_velocity);
    write(f, m_size);
    f.close();
}

void Entity::readObject() {
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2i siz;
    std::ifstream f(filepath, f.binary);
    read(f, pos);
    read(f, vel);
    read(f, siz);
    f.close();
    printf("{%f,%f}, {%f,%f}, {%d,%d}\n", pos.x, pos.y, vel.x, vel.y, siz.x, siz.y);
}
