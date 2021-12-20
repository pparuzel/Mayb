#ifndef MAYBSFML_WORLDMAKER_HPP
#define MAYBSFML_WORLDMAKER_HPP

#include "../Config.hpp"
#include "../Rendering/RenderManager.hpp"
#include "States/FunctionManager.hpp"
#include <SFML/Graphics.hpp>

class WorldMaker
{
    sf::RenderWindow window_;
    FunctionManager functionManager_;
    RenderManager renderer_;

public:
    explicit WorldMaker(const Config& config);

    void run();
};

#endif  // MAYBSFML_WORLDMAKER_HPP
