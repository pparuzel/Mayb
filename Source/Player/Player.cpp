#include "Player.hpp"

Player::Player()
        : Entity{{50.f, 100.f}} {}

float speed = 500.f;

void Player::handleKeyboardInput(float dt) {
    velocity.x = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x -= speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x += speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and grounded) {
        velocity.y = -20.f;
        grounded = false;
    }
}

void Player::update(float dt) {
    handleKeyboardInput(dt);
    // Gravitational pull
    velocity.y += 1.f;
}

void Player::move() {
    position.x += velocity.x;
    position.y += velocity.y;
}
