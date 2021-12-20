#ifndef MAYBSFML_ENTITY_HPP
#define MAYBSFML_ENTITY_HPP

#include "Maths/Collider.hpp"
#include "Rendering/Renderable.hpp"
#include "States/Serializable.hpp"

class Entity
    : public Renderable
    , public Serializable
{
    sf::Vector2i size_;
    Collider bounds_;

protected:
    sf::Vector2f velocity_;
    sf::Vector2f position_;
    bool grounded;

public:
    explicit Entity(sf::Vector2i size,
                    sf::Vector2f position = {0, 0},
                    sf::Vector2i offset = {0, 0});

    void resolveCollision(CollisionType);

    const sf::Vector2f& velocity() const;

    Collider& AABBox();

    void writeObject() override;

    void readObject() override;

    ~Entity() override
    {
        //        writeObject();
        //        readObject();
    }
};

#endif  // MAYBSFML_ENTITY_HPP
