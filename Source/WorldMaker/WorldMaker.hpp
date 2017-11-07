#ifndef MAYBSFML_WORLDMAKER_HPP
#define MAYBSFML_WORLDMAKER_HPP


#include <SFML/Graphics.hpp>
#include "../Config.hpp"
#include "../Rendering/RenderManager.hpp"
#include "States/FunctionManager.hpp"

class WorldMaker {
    sf::RenderWindow        m_window;
    FunctionManager         m_functionManager;
    RenderManager           m_renderer;
public:
    explicit WorldMaker(const Config& config);

    void run();
};


#endif //MAYBSFML_WORLDMAKER_HPP
