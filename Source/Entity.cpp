#include "Entity.hpp"

Entity::Entity(Vector2 size_, Vector2 pos, Vector2 vel)
        : size(size_), position(pos), velocity(vel), bounding_box(position, size), grounded(false) {}

void Entity::resolveCollision(COLLISION_TYPE collType) {
    if (collType == VERTICAL) {
        velocity.x = 0;
        grounded = false;
    } else if (collType == HORIZONTAL || collType == HORIZONTAL_GROUND) {
        velocity.y = 0;
    } else if (collType == BOTH || collType == BOTH_GROUND) {
        velocity = {0, 0};
        grounded = false;
    }
    if (collType == HORIZONTAL_GROUND || collType == BOTH_GROUND) {
        grounded = true;
    }
}
