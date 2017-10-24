#ifndef MAYBSFML_APPLICATION_H
#define MAYBSFML_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Utils/FPSCounter.hpp"
#include "Scenes/SplashScreen.hpp"
#include "Scenes/GameScene.hpp"
#include "Scenes/MenuScene.hpp"
#include "Scenes/Scene.hpp"
#include "Config.hpp"

class Application {
    RenderManager               m_renderer;
    sf::RenderWindow            m_window;
    std::unique_ptr<FPSCounter> m_fpsCounter;
    std::unique_ptr<Scene>      m_scene;
    const Config&               m_config;
public:
    explicit Application(const Config&);

    void handleEvents();

    void run();
};


#endif //MAYBSFML_APPLICATION_H
