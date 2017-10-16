#ifndef MAYBSFML_CONTROLLER_HPP
#define MAYBSFML_CONTROLLER_HPP


#include <SFML/Graphics.hpp>
#include "../Entity.hpp"

class Player : public Entity {

public:
    void handleKeyboardInput();
};


#endif //MAYBSFML_CONTROLLER_HPP
