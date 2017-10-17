#ifndef MAYBSFML_FPSCOUNTER_H
#define MAYBSFML_FPSCOUNTER_H


#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>
#include "../Rendering/RenderManager.hpp"

class FPSCounter {
    sf::Clock m_fpsTimer;
    sf::Clock m_tickTimer;
    sf::Font m_font;
    sf::Text m_text;

    int m_currentFrames;
    float m_fps;
    float m_lastTick;
public:
    FPSCounter();

    void update();
    void draw(const RenderManager& );
    float frametime() const;
};


#endif //MAYBSFML_FPSCOUNTER_H
