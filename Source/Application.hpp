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
    std::unique_ptr<FPSCounter> m_fpsCounter;
    std::unique_ptr<Scene>      m_scene;
    RenderManager               m_renderer;
    sf::RenderWindow            m_window;
    const Config&               m_config;
public:
    explicit Application(const Config&);

    void handleEvents();

    void run();
private:
    void changeScene();
};


#endif //MAYBSFML_APPLICATION_H
