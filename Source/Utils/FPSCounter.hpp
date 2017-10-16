#ifndef MAYBSFML_FPSCOUNTER_H
#define MAYBSFML_FPSCOUNTER_H


#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>
#include "../Rendering/RenderManager.hpp"

class FPSCounter {
    sf::Clock m_timer;
    sf::Font m_font;
    sf::Text m_text;

    int m_currentFrames;
    float m_fps;
public:
    FPSCounter();

    void update();
    void draw(const RenderManager& );
};


#endif //MAYBSFML_FPSCOUNTER_H
