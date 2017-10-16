#ifndef MAYBSFML_GAMESCENE_HPP
#define MAYBSFML_GAMESCENE_HPP


#include "Scene.hpp"
#include "../World/World.hpp"

class GameScene : public Scene {
    World m_world;
public:
    GameScene(const Config&);

    void generate() override;

    void render(const RenderManager& renderer) override;
};


#endif //MAYBSFML_GAMESCENE_HPP
