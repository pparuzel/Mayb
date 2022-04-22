#include "Application.hpp"

#include "Scenes/GameScene.hpp"
#include "Scenes/MenuScene.hpp"
#include "Scenes/SplashScreen.hpp"
#include "Scenes/BootloadScene.hpp"
#include "Config.hpp"

Application::Application()
    : window_{sf::VideoMode(getConfig().width, getConfig().height), "Mayb2D", sf::Style::Close}
    , scene_{std::make_unique<Bootload>(window_)}
{
}

void Application::run()
{
    while (window_.isOpen())
    {
        if (!scene_->updateAndRender(window_))
        {
            changeScene(scene_->nextScene());
        }
    }
}

void Application::changeScene(SceneType type)
{
    switch (type)
    {
        case SceneType::SplashScreen:
            scene_ = std::make_unique<SplashScreen>(window_);
            break;
        case SceneType::MenuScene:
            scene_ = std::make_unique<MenuScene>(window_);
            break;
        case SceneType::GameScene:
            scene_ = std::make_unique<GameScene>(window_);
            break;
        default:
            std::terminate();
    }
}
