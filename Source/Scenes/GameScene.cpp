#include "GameScene.hpp"

GameScene::GameScene(const Config& config) : m_world(config) {}

void GameScene::generate() {
    m_world.generate();
}

void GameScene::render(const RenderManager& renderer) {
    m_world.render(renderer);
}
