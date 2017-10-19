#ifndef MAYBSFML_CONTROLLER_HPP
#define MAYBSFML_CONTROLLER_HPP


#include <SFML/Graphics.hpp>
#include "../Entity.hpp"
#include "../Rendering/RenderManager.hpp"

class Player : public Entity {

public:
    Player();

    void handleKeyboardInput(float );

    void update(float );

    void move();

    void draw(const RenderManager&);
};


#endif //MAYBSFML_CONTROLLER_HPP
