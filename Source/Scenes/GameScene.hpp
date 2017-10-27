#ifndef MAYBSFML_GAMESCENE_HPP
#define MAYBSFML_GAMESCENE_HPP


#include "Scene.hpp"
#include "../Utils/FPSCounter.hpp"
#include "../Player/Player.hpp"
#include "../World/World.hpp"

class GameScene : public Scene {
    World               m_world;
    const FPSCounter&   m_counter;
public:
    GameScene(const Config&, const FPSCounter& );

    void update() override;

    void render(const RenderManager& renderer) override;

    const std::string nextScene() const override;

    void handleEvents(sf::RenderWindow& window) override;
};


#endif //MAYBSFML_GAMESCENE_HPP
