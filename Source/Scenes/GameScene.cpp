#include "Scenes/GameScene.hpp"

#include "Config.hpp"

GameScene::GameScene(sf::RenderWindow& window)
    : world_()
    , counter_()
{
    auto& config = getConfig();
    config.isVSyncEnabled = true;
    config.fpsCap = 60;
    config.reconfigureWindow(window);
}

void GameScene::doUpdate()
{
    if (!popUpMenu.isOpen())
    {
        world_.update(counter_.frametime());
    }
}

void GameScene::doRender(sf::RenderWindow& window)
{
    world_.render(window);
    if (popUpMenu.isOpen())
    {
        popUpMenu.render(window);
    }
    // TODO: Possible HUD rendering here...
}

SceneType GameScene::nextScene() const
{
    return SceneType::MenuScene;
}

bool GameScene::doHandleEvents(sf::RenderWindow& window)
{
    bool isRunning = true;
    if (world_.isGameOver())
    {
        isRunning = false;
    }
    if (popUpMenu.isOpen())
    {
        popUpMenu.update(window, isRunning);
        return isRunning;
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
    return isRunning;
}
