#include "Vector2.hpp"

sf::Vector2f Vector2::toSFML() const {
    return sf::Vector2f(x, y);
}

Vector2::Vector2(float x_, float y_) : x(x_), y(y_) {}

Vector2 Vector2::operator+(const Vector2& other) {
    return Vector2(x + other.x, y + other.y);
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 Vector2::operator*(float n) {
    return Vector2(x * n, y * n);
}

Vector2 Vector2::operator+(float n) {
    return Vector2(x + n, y + n);
}
