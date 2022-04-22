#include "BootloadScene.hpp"

#include "Config.hpp"

Bootload::Bootload(sf::RenderWindow& window)
{
    getConfig().reconfigureWindow(window);
}

SceneType Bootload::nextScene() const
{
    if (getConfig().skipSplashScreen)
    {
        return SceneType::MenuScene;
    }
    return SceneType::SplashScreen;
}
