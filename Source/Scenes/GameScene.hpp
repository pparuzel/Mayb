#ifndef MAYBSFML_GAMESCENE_HPP
#define MAYBSFML_GAMESCENE_HPP


#include "Scene.hpp"
#include "../World/World.hpp"
#include "../Player/Player.hpp"
#include "../Utils/FPSCounter.hpp"

class GameScene : public Scene {
    World m_world;
    Player m_player;
    const FPSCounter& m_counter;
public:
    GameScene(const Config&, const FPSCounter& );

    void update() override;

    void render(const RenderManager& renderer) override;

};


#endif //MAYBSFML_GAMESCENE_HPP
