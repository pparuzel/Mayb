#include "MenuScene.hpp"

MenuScene::MenuScene(const Config& config, const FPSCounter& fpsCounter)
        : m_fpsCounter(fpsCounter), m_currentButton(0), m_buttons() {
    m_buttons.build("menu_bg.png", {0.f, 0.f});
    m_buttons.build("newgame_button.png", {360, 200});
    m_buttons.build("exit_button.png", {360, 320});
}

void MenuScene::render(const RenderManager& renderer) {
    renderer.refresh(sf::Color{153, 204, 255});
    for (const auto& button : m_buttons.sprites()) {
        renderer.loadSprite(button);
    }
    sf::RectangleShape indicator({548, 96});
    indicator.setFillColor(sf::Color{0, 0, 0, 80});
    indicator.setPosition(360, 200 + 120*m_currentButton);
    renderer.drawSFML(indicator);
}

int numberOfButtons = 2;

void MenuScene::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        switch(m_currentButton) {
            case 0:
                hasFinished = true;
                break;
            case 1:
                break;
            default:
                break;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_currentButton = --m_currentButton < 0 ? numberOfButtons-1 : m_currentButton;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_currentButton = ++m_currentButton > numberOfButtons-1 ? 0 : m_currentButton;
    }
}

const std::string MenuScene::nextScene() const {
    return "GameScene";
}