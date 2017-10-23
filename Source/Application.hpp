#ifndef MAYBSFML_APPLICATION_H
#define MAYBSFML_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Utils/FPSCounter.hpp"
#include "Scenes/GameScene.hpp"
#include "Scenes/Scene.hpp"
#include "Config.hpp"

class Application {
    sf::RenderWindow            m_window;
    RenderManager               m_renderer;
    std::unique_ptr<FPSCounter> m_fpsCounter;
    std::unique_ptr<Scene>      m_scene;
    const Config&               m_config;
public:
    explicit Application(const Config&);

    void handleEvents();

    void run();
};


#endif //MAYBSFML_APPLICATION_H
