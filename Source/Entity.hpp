#ifndef MAYBSFML_ENTITY_HPP
#define MAYBSFML_ENTITY_HPP


#include <SFML/Graphics.hpp>
#include "Maths/Vector2.hpp"
#include "Maths/Collider.hpp"


class Entity {
protected:
    Vector2 position;
    Vector2 velocity;
    Collider bounding_box;
    friend class World;
public:
    Entity(Vector2 pos={0, 0}, Vector2 vel={0, 0}, Vector2 size={0, 0});

    const Vector2& getPosition() const;
};


#endif //MAYBSFML_ENTITY_HPP
