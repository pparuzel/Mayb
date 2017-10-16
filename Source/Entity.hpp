#ifndef MAYBSFML_ENTITY_HPP
#define MAYBSFML_ENTITY_HPP


#include <SFML/Graphics.hpp>
#include "Maths/Vector2.hpp"
#include "Maths/Collider.hpp"

class Entity {
protected:
    Vector2 position;
    Vector2 velocity;
    Collider collision_box;
public:
    Entity(Collider box, Vector2 pos={0, 0}, Vector2 vel={0, 0});

    virtual ~Entity() = 0;
};


#endif //MAYBSFML_ENTITY_HPP
