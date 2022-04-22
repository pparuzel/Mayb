#ifndef MAYBSFML_FPSCOUNTER_H
#define MAYBSFML_FPSCOUNTER_H

#include <SFML/Graphics.hpp>

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
    explicit FPSCounter();

    void update();
    void draw(sf::RenderWindow&);
    float frametime() const;
};

#endif  // MAYBSFML_FPSCOUNTER_H
