#include "Player.hpp"

Player::Player()
        : Entity{{50.f, 100.f}} {}

float speed = .5f;

void Player::handleKeyboardInput(float dt) {
    velocity.x = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and grounded) {
        velocity.y -= .5515f;
        grounded = false;
    }
}

void Player::update(float dt) {
    handleKeyboardInput(dt);
    // gravitational pull
    velocity.y += .0015f * dt;
}

void Player::move(float dt) {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
}
