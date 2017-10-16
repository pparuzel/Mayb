#ifndef MAYBSFML_APPLICATION_H
#define MAYBSFML_APPLICATION_H

#include <SFML/Graphics.hpp>
#include "Config.hpp"
#include "Utils/FPSCounter.hpp"

class Application {
    sf::RenderWindow m_window;
    RenderManager m_renderer;
    FPSCounter m_fpsCounter;
public:
    Application(const Config&);

    void handleEvents();

    void run();
};


#endif //MAYBSFML_APPLICATION_H
