#ifndef MAYBSFML_VECTOR2_HPP
#define MAYBSFML_VECTOR2_HPP


#include <SFML/Graphics.hpp>

struct Vector2 {
    float x;
    float y;

    Vector2(float _x, float _y);

    sf::Vector2f toSFML() const;

    Vector2 operator+(const Vector2& );

    Vector2 operator+(float );

    Vector2& operator+=(const Vector2& );

    Vector2 operator*(float );
};


#endif //MAYBSFML_VECTOR2_HPP
