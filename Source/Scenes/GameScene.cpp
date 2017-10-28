#include "GameScene.hpp"

GameScene::GameScene(const Config& config, const FPSCounter& fpsCounter)
        : m_world(config), m_counter(fpsCounter), popUpMenu() {
}

void GameScene::update() {
    if (not popUpMenu.isOpen()) {
        m_world.update(m_counter.frametime());
    }
    if (m_world.isGameOver()) {
        hasFinished = true;
    }
}

void GameScene::render(const RenderManager& renderer) {
    m_world.render(renderer);
    if (popUpMenu.isOpen()) {
        popUpMenu.render(renderer);
    }
    // TODO Possible HUD rendering here...
}

const std::string GameScene::nextScene() const {
    return "MenuScene";
}

void GameScene::handleEvents(sf::RenderWindow& window) {
    if (popUpMenu.isOpen()) {
        popUpMenu.update(window, hasFinished);
        return;
    }
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                popUpMenu.toggle();
            }
        }
    }
}
