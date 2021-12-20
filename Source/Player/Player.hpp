#ifndef MAYBSFML_CONTROLLER_HPP
#define MAYBSFML_CONTROLLER_HPP

#include "../Entity.hpp"
#include "../Rendering/RenderManager.hpp"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
    int animCounter_;

public:
    explicit Player(sf::Vector2f position = {0, 0});

    void handleKeyboardInput(float);

    void update(float);

    void move();

private:
    static constexpr float speed = 500.f;
    static constexpr int animDelay = 14;

    void writeObject() override;

    void readObject() override;
};

#endif  // MAYBSFML_CONTROLLER_HPP
