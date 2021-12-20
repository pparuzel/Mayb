#include "Collider.hpp"

Collider::Collider(sf::Vector2f& position,
                   sf::Vector2i bodySize,
                   sf::Vector2i horizMargin,
                   sf::Vector2i vertMargin)
    : position_(position)
    , bodySize_(bodySize)
    , hMargin_(horizMargin)
    , vMargin_(vertMargin)
{
}

CollisionType Collider::detectRectCollision(const Collider& c, sf::Vector2f change)
{
    const float l = position_.x - hMargin_.x;
    const float r = position_.x + bodySize_.x + hMargin_.y;
    const float t = position_.y - vMargin_.x;
    const float b = position_.y + bodySize_.y + vMargin_.y;
    const float cl = c.position_.x;
    const float cr = c.position_.x + c.bodySize_.x;
    const float ct = c.position_.y;
    const float cb = c.position_.y + c.bodySize_.y;
    const float dx = change.x;
    const float dy = change.y;
    CollisionType collType = CollisionType::NoCollision;
    if (l + dx < cr && r + dx > cl && t < cb && b > ct)
    {
        if (dx > 0.f)
        {
            position_.x = cl - bodySize_.x - hMargin_.y;
        }
        else
        {
            position_.x = cr + hMargin_.x;
        }
        collType = CollisionType::Vertical;
    }
    if (l < cr && r > cl && t + dy < cb && b + dy > ct)
    {
        if (dy > 0.f)
        {
            position_.y = ct - bodySize_.y - vMargin_.y;
            collType = static_cast<CollisionType>(
                static_cast<int>(collType)
                + static_cast<int>(CollisionType::HorizontalGround));
        }
        else
        {
            position_.y = cb + vMargin_.x;
            collType = static_cast<CollisionType>(
                static_cast<int>(collType) + static_cast<int>(CollisionType::Horizontal));
        }
    }

    return collType;
}

void Collider::setMargin(int top, int bottom, int left, int right)
{
    vMargin_ = {top, bottom};
    hMargin_ = {left, right};
}
