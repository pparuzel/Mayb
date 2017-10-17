#include "Entity.hpp"

Entity::Entity(Vector2 pos, Vector2 vel, Vector2 size)
        : position(pos), velocity(vel), bounding_box(position, size) {}
