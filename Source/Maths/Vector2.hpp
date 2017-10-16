#ifndef MAYBSFML_VECTOR2_HPP
#define MAYBSFML_VECTOR2_HPP


#include <SFML/Graphics.hpp>

struct Vector2 {
    float x;
    float y;

    Vector2(float _x, float _y);

    sf::Vector2f toSFML() const;

};


#endif //MAYBSFML_VECTOR2_HPP
