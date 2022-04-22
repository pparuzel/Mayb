#include "Player/Player.hpp"

#include "TextureCache.hpp"

Player::Player(sf::Vector2f position)
    : Entity{{80, 110}, position}
    , animCounter_(0)
{
    auto&& cache = TextureCache::getInstance();
    texture_ = &cache.load("Player", std_fs::path("World") / "player.png");
    texture_mirror_ = &cache.load("PlayerMirror", std_fs::path("World") / "player_mirror.png");
    AABBox().setMargin(-5, 0, 0, 0);
    sprite_.setTexture(*texture_);
    sprite_.setTextureRect(indicator_);
}

void Player::handleKeyboardInput(float dt)
{
    velocity_.x = 0;
    indicator_.left = 0;
    indicator_.top = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity_.x -= speed * dt;
        sprite_.setTexture(*texture_mirror_);
        indicator_.top = 110;
        indicator_.left = 80;
        if (animCounter_ > 7)
        {
            indicator_.left = (indicator_.left + 80) % 160;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity_.x += speed * dt;
        sprite_.setTexture(*texture_);
        indicator_.top = 110;
        if (animCounter_ > animDelay / 2)
        {
            indicator_.left = (indicator_.left + 80) % 160;
        }
    }
    animCounter_ = (animCounter_ + 1) % animDelay;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and grounded and velocity_.y == 0)
    {
        velocity_.y = -20.f;
        grounded = false;
    }
}

void Player::update(float dt)
{
    handleKeyboardInput(dt);
    // Apply gravity
    velocity_.y += 1.f;
}

void Player::move()
{
    if (not grounded and velocity_.y != 0)
    {
        indicator_.top = 0;
        indicator_.left = velocity_.y < 0.f ? 80 : 160;
    }
    position_.x += velocity_.x;
    position_.y += velocity_.y;
    sprite_.setPosition(position_);
    sprite_.setTextureRect(indicator_);
}

void Player::writeObject()
{
    std::ofstream f(filepath + "Player.ser", std::ofstream::binary);
    write(f, position_);
    write(f, velocity_);
    f.close();
}

void Player::readObject()
{
    sf::Vector2f pos;
    sf::Vector2f vel;
    std::ifstream f(filepath + "Player.ser", std::ofstream::binary);
    read(f, pos);
    read(f, vel);
    f.close();
    printf("{%f,%f}, {%f,%f}\n", pos.x, pos.y, vel.x, vel.y);
}
