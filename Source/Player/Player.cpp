#include "Player.hpp"

Player::Player()
        : Entity{{70.f, 110.f}}, animCounter(0) {
    texture.loadFromFile("../Resources/player.png");
    texture_mirror.loadFromFile("../Resources/player_mirror.png");
    sprite.setTexture(texture);
}

float speed = 500.f;

void Player::handleKeyboardInput(float dt) {
    velocity.x = 0;
    rect.left = 0;
    rect.top = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x -= speed * dt;
        sprite.setTexture(texture_mirror);
        rect.top = 110;
        rect.left = 80;
        if (animCounter > 7) {
            rect.left = (rect.left + 80) % 160;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x += speed * dt;
        sprite.setTexture(texture);
        rect.top = 110;
        if (animCounter > 7) {
            rect.left = (rect.left + 80) % 160;
        }
    }
    animCounter = (animCounter + 1) % 14;
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
    if (not grounded and velocity.y != 0) {
        rect.top = 0;
        if (velocity.y < 0.f) rect.left = 80;
        else rect.left = 160;
    }
    position.x += velocity.x;
    position.y += velocity.y;
}
