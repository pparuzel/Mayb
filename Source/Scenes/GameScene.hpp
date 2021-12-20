#ifndef MAYBSFML_GAMESCENE_HPP
#define MAYBSFML_GAMESCENE_HPP

#include "../Player/Player.hpp"
#include "../Utils/FPSCounter.hpp"
#include "../World/World.hpp"
#include "PopUpMenu.hpp"
#include "Scene.hpp"

class GameScene : public Scene
{
    World world_;
    const FPSCounter& counter_;
    PopUpMenu popUpMenu;

public:
    GameScene(const Config&, const FPSCounter&);

    void update() override;

    void render(const RenderManager& renderer) override;

    std::string_view nextScene() const override;

    void handleEvents(sf::RenderWindow& window) override;
};

#endif  // MAYBSFML_GAMESCENE_HPP
