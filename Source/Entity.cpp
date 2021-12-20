#include "Entity.hpp"

Entity::Entity(sf::Vector2i size, sf::Vector2f position, sf::Vector2i offset)
    : size_(size)
    , position_(position)
    , velocity_({0.f, 0.f})
    , bounds_(position_, size)
    , grounded(false)
    , Renderable(offset, size)
    , Serializable()
{
    sprite_.setTextureRect(indicator_);
    sprite_.setPosition(position);
}

void Entity::resolveCollision(CollisionType collType)
{
    if (collType == CollisionType::Vertical)
    {
        velocity_.x = 0;
        grounded = false;
    }
    else if (collType == CollisionType::Horizontal
             || collType == CollisionType::HorizontalGround)
    {
        velocity_.y = 0;
    }
    else if (collType == CollisionType::Both || collType == CollisionType::BothGround)
    {
        velocity_ = {0, 0};
        grounded = false;
    }
    if (collType == CollisionType::HorizontalGround || collType == CollisionType::BothGround)
    {
        grounded = true;
    }
}

const sf::Vector2f& Entity::velocity() const
{
    return velocity_;
}

Collider& Entity::AABBox()
{
    return bounds_;
}

void Entity::writeObject()
{
    std::ofstream f(filepath + "Entity.ser", f.binary);
    write(f, position_);
    write(f, velocity_);
    write(f, size_);
    f.close();
}

void Entity::readObject()
{
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2i siz;
    std::ifstream f(filepath + "Entity.ser", f.binary);
    read(f, pos);
    read(f, vel);
    read(f, siz);
    f.close();
    printf("{%f,%f}, {%f,%f}, {%d,%d}\n", pos.x, pos.y, vel.x, vel.y, siz.x, siz.y);
}
