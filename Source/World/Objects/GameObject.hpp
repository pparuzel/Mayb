#ifndef MAYBSFML_GAMEOBJECT_HPP
#define MAYBSFML_GAMEOBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject
{
    sf::Vector2i size_;

protected:
    sf::Vector2f position_;
    sf::IntRect indicator_;

public:
    explicit GameObject(sf::Vector2f position, sf::Vector2i size, sf::Vector2i offset);

    sf::Vector2f position() const;

    virtual ~GameObject() = default;
};

#endif  // MAYBSFML_GAMEOBJECT_HPP
