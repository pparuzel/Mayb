#include "Vector2.hpp"

sf::Vector2f Vector2::toSFML() const {
    return sf::Vector2f(x, y);
}

Vector2::Vector2(float x_, float y_) : x(x_), y(y_) {}
