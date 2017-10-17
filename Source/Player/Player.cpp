#include "Player.hpp"

Player::Player()
        : Entity() {}

float accel = .01f;

int sgn(float x) {
    if (x == 0) return 0;
    return x > 0 ? 1 : -1;
}

float abs(float x) {
    return x > 0 ? x : -x;
}

void Player::handleKeyboardInput(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && velocity.x > -2.f) {
        velocity.x -= accel * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && velocity.x < 2.f) {
        velocity.x += accel * dt;
    }
    if (abs(velocity.x) > 1.f) velocity.x = sgn(velocity.x) * 1.f;
}

void Player::update(float dt) {
    handleKeyboardInput(dt);
    velocity.y += accel * dt; // gravitational pull
    position += velocity * dt;
}

void Player::draw(const RenderManager& renderer) {
    renderer.drawEntity(*this);
}
