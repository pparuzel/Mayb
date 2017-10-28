#include "Player.hpp"

Player::Player(sf::Vector2f position)
        : Entity{{80, 110}, position}, m_animCounter(0) {
    m_texture.loadFromFile("../Resources/World/player.png");
    m_texture_mirror.loadFromFile("../Resources/World/player_mirror.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(m_indicator);
}

void Player::handleKeyboardInput(float dt) {
    m_velocity.x = 0;
    m_indicator.left = 0;
    m_indicator.top = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_velocity.x -= speed * dt;
        m_sprite.setTexture(m_texture_mirror);
        m_indicator.top = 110;
        m_indicator.left = 80;
        if (m_animCounter > 7) {
            m_indicator.left = (m_indicator.left + 80) % 160;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_velocity.x += speed * dt;
        m_sprite.setTexture(m_texture);
        m_indicator.top = 110;
        if (m_animCounter > animDelay / 2) {
            m_indicator.left = (m_indicator.left + 80) % 160;
        }
    }
    m_animCounter = (m_animCounter + 1) % animDelay;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and grounded and m_velocity.y == 0) {
        m_velocity.y = -20.f;
        grounded = false;
    }
}

void Player::update(float dt) {
    handleKeyboardInput(dt);
    // Apply gravity
    m_velocity.y += 1.f;
}

void Player::move() {
    if (not grounded and m_velocity.y != 0) {
        m_indicator.top = 0;
        if (m_velocity.y < 0.f) m_indicator.left = 80;
        else m_indicator.left = 160;
    }
    m_position.x += m_velocity.x;
    m_position.y += m_velocity.y;
    m_sprite.setPosition(m_position);
    m_sprite.setTextureRect(m_indicator);
}

void Player::writeObject() {
    std::ofstream f(filepath + "Player.ser", f.binary);
    write(f, m_position);
    write(f, m_velocity);
    f.close();
}

void Player::readObject() {
    sf::Vector2f pos;
    sf::Vector2f vel;
    std::ifstream f(filepath + "Player.ser", f.binary);
    read(f, pos);
    read(f, vel);
    f.close();
    printf("{%f,%f}, {%f,%f}\n", pos.x, pos.y, vel.x, vel.y);
}
