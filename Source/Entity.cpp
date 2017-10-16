#include "Entity.hpp"

Entity::Entity(Collider box, Vector2 pos, Vector2 vel)
        : position(pos), velocity(vel), collision_box(box) {}
