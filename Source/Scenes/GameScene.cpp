#include "Scenes/GameScene.hpp"

GameScene::GameScene(const Config& config, const FPSCounter& fpsCounter)
    : world_(config)
    , counter_(fpsCounter)
{
}

void GameScene::update()
{
    if (not popUpMenu.isOpen())
    {
        world_.update(counter_.frametime());
    }
    if (world_.isGameOver())
    {
        endScene();
    }
}

void GameScene::render(const RenderManager& renderer)
{
    world_.render(renderer);
    if (popUpMenu.isOpen())
    {
        popUpMenu.render(renderer);
    }
    // TODO Possible HUD rendering here...
}

std::string_view GameScene::nextScene() const
{
    return "MenuScene";
}

void GameScene::handleEvents(sf::RenderWindow& window)
{
    if (popUpMenu.isOpen())
    {
        popUpMenu.update(window, *this);
        return;
    }
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                popUpMenu.toggle();
            }
        }
    }
}
