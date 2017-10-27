#include "GameScene.hpp"

GameScene::GameScene(const Config& config, const FPSCounter& fpsCounter)
        : m_world(config), m_counter(fpsCounter) {
}

void GameScene::update() {
    m_world.update(m_counter.frametime());
    if (m_world.isGameOver()) {
        hasFinished = true;
    }
}

void GameScene::render(const RenderManager& renderer) {
    // TODO Event handling for every scene
    m_world.render(renderer);
    // TODO Possible HUD rendering here...
}

const std::string GameScene::nextScene() const {
    return "MenuScene";
}

void GameScene::handleEvents(sf::RenderWindow& window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}
