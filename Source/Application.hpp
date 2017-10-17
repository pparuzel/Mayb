#ifndef MAYBSFML_APPLICATION_H
#define MAYBSFML_APPLICATION_H

#include <SFML/Graphics.hpp>
#include "Config.hpp"
#include "Utils/FPSCounter.hpp"
#include "Scenes/Scene.hpp"
#include "Scenes/GameScene.hpp"
#include <memory>

class Application {
    sf::RenderWindow m_window;
    RenderManager m_renderer;
    FPSCounter m_fpsCounter;
    std::unique_ptr<Scene> m_scene;
    const Config& m_config;
public:
    Application(const Config&);

    void handleEvents();

    void run();
};


#endif //MAYBSFML_APPLICATION_H
