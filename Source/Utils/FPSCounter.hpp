#ifndef MAYBSFML_FPSCOUNTER_H
#define MAYBSFML_FPSCOUNTER_H

#include "../Rendering/RenderManager.hpp"
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <sstream>

class FPSCounter
{
    sf::Clock fpsTimer_;
    sf::Clock tickTimer_;
    sf::Font font_;
    sf::Text text_;
    int currentFrames_;
    float fps_;
    float lastTick_;

public:
    FPSCounter();

    void update();
    void draw(const RenderManager&);
    float frametime() const;
};

#endif  // MAYBSFML_FPSCOUNTER_H
