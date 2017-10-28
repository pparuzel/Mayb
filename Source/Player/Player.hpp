#ifndef MAYBSFML_CONTROLLER_HPP
#define MAYBSFML_CONTROLLER_HPP


#include <SFML/Graphics.hpp>
#include "../Rendering/RenderManager.hpp"
#include "../Entity.hpp"

class Player : public Entity {
    int m_animCounter;
public:
    explicit Player(sf::Vector2f position={0, 0});

    void handleKeyboardInput(float);

    void update(float);

    void move();

private:
    static constexpr float  speed = 500.f;
    static constexpr int    animDelay = 14;

    void writeObject() override;

    void readObject() override;
};


#endif //MAYBSFML_CONTROLLER_HPP
