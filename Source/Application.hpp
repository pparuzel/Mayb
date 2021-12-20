#ifndef MAYBSFML_APPLICATION_H
#define MAYBSFML_APPLICATION_H

#include "Config.hpp"
#include "Scenes/GameScene.hpp"
#include "Scenes/MenuScene.hpp"
#include "Scenes/Scene.hpp"
#include "Scenes/SplashScreen.hpp"
#include "Utils/FPSCounter.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Application
{
    std::unique_ptr<FPSCounter> fpsCounter_;
    std::unique_ptr<Scene> scene_;
    RenderManager renderer_;
    sf::RenderWindow window_;
    const Config& config_;

public:
    explicit Application(const Config&);

    void run();

private:
    void changeScene();
};

#endif  // MAYBSFML_APPLICATION_H
