#include "Entity.hpp"

Entity::Entity(Vector2 size_, Vector2 pos, Vector2 vel)
        : size(size_), position(pos), velocity(vel), bounding_box(position, size) {}


Collider& Entity::getCollider() {
    return bounding_box;
}

void Entity::resolveCollision(COLLISION_TYPE col_type) {
    if (col_type == COLLISION_TYPE::VERTICAL) {
        velocity.x = 0;
    } else if (col_type == COLLISION_TYPE::HORIZONTAL) {
        velocity.y = 0;
    } else {
        velocity = {0, 0};
    }
}
