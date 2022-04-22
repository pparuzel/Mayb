#ifndef MAYBSFML_GAMESCENE_HPP
#define MAYBSFML_GAMESCENE_HPP

#include "Player/Player.hpp"
#include "Scenes/PopUpMenu.hpp"
#include "Scenes/Scene.hpp"
#include "Utils/FPSCounter.hpp"
#include "World/World.hpp"

class GameScene : public Scene
{
    World world_;
    FPSCounter counter_;
    PopUpMenu popUpMenu;

public:
    explicit GameScene(sf::RenderWindow& window);
    SceneType nextScene() const override;

private:
    void doUpdate() override;
    void doRender(sf::RenderWindow& window) override;
    bool doHandleEvents(sf::RenderWindow& window) override;
};

#endif  // MAYBSFML_GAMESCENE_HPP
