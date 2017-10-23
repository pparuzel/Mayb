#include "GameScene.hpp"

GameScene::GameScene(const Config& config, const FPSCounter& fpsCounter)
        : m_world(config), m_counter(fpsCounter) {
}

void GameScene::update() {
    m_world.update(m_counter.frametime());
}

void GameScene::render(const RenderManager& renderer) {
    m_world.render(renderer);
    // TODO Possible HUD rendering here...
}
