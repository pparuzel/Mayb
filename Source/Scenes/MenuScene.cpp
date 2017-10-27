#include "MenuScene.hpp"

MenuScene::MenuScene(const Config& config, const FPSCounter& fpsCounter,
                     sf::RenderWindow* window)
        : m_fpsCounter(fpsCounter), m_currentButton(0),
          m_buttons(), m_window(window) {
    m_buttons.build("MainMenu/menu_bg.png", {0.f, 0.f});
    m_buttons.build("MainMenu/newgame_button.png", {360, 200});
    m_buttons.build("MainMenu/load_button.png", {360, 320});
    m_buttons.build("MainMenu/exit_button.png", {360, 440});
    m_numberOfButtons = 3;
    m_locked = true;
}

void MenuScene::render(const RenderManager& renderer) {
    renderer.refresh(sf::Color{153, 204, 255});
    for (const auto& button : m_buttons.sprites()) {
        renderer.loadSprite(button);
    }
    sf::RectangleShape indicator({548, 96});
    indicator.setFillColor(sf::Color{255, 255, 255, 80});
    indicator.setPosition(360, 200 + 120*m_currentButton);
    renderer.drawSFML(indicator);
}

void MenuScene::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        switch(m_currentButton) {
            case 0:
                hasFinished = true;
                break;
            case 2:
                m_window->close();
                break;
            default:
                break;
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and not m_locked) {
        m_currentButton = --m_currentButton < 0 ? m_numberOfButtons-1 : m_currentButton;
        m_locked = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and not m_locked) {
        m_currentButton = ++m_currentButton > m_numberOfButtons-1 ? 0 : m_currentButton;
        m_locked = true;
    } else if (not sf::Keyboard::isKeyPressed(sf::Keyboard::W)
            and not sf::Keyboard::isKeyPressed(sf::Keyboard::S)) m_locked = false;
}

const std::string MenuScene::nextScene() const {
    return "GameScene";
}

void MenuScene::handleEvents(sf::RenderWindow& window) {

}
