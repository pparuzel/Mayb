#ifndef MAYBSFML_GAMEOBJECT_HPP
#define MAYBSFML_GAMEOBJECT_HPP


#include <SFML/Graphics.hpp>

class GameObject {
    sf::Vector2i        m_size;
protected:
    sf::Vector2f        m_position;
    sf::IntRect         m_indicator;
public:
    explicit GameObject(sf::Vector2f position, sf::Vector2i size, sf::Vector2i offset);

    sf::Vector2f position() const;

    virtual ~GameObject() = default;
};


#endif //MAYBSFML_GAMEOBJECT_HPP
