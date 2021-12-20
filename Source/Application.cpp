#include "Application.hpp"

Application::Application(const Config& config)
    : renderer_(window_)
    , config_(config)
{

    fpsCounter_ = std::make_unique<FPSCounter>();
    scene_ = std::make_unique<SplashScreen>(config, *fpsCounter_);
    window_.create(sf::VideoMode(config.width, config.height), "Mayb2D", sf::Style::Close);
    window_.setFramerateLimit(config.fps_cap);
    window_.setVerticalSyncEnabled(config.isVSyncOn);
}

void Application::run()
{
    while (window_.isOpen())
    {
        fpsCounter_->update();
        scene_->handleEvents(window_);
        scene_->update();

        window_.clear(sf::Color::Black);
        scene_->render(renderer_);
        fpsCounter_->draw(renderer_);
        window_.display();
        if (scene_->closed())
            changeScene();
    }
}

void Application::changeScene()
{
    Scene* scene_ptr = nullptr;
    if (scene_->nextScene() == "GameScene")
        scene_ptr = new GameScene(config_, *fpsCounter_);
    else if (scene_->nextScene() == "MenuScene")
        scene_ptr = new MenuScene(config_, *fpsCounter_);
    else if (scene_->nextScene() == "Exit")
        window_.close();
    else
        throw "Wrong classname!\n";
    scene_.reset(scene_ptr);
}
