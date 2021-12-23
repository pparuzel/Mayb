#include "MenuScene.hpp"

MenuScene::MenuScene(const Config& config, const FPSCounter& fpsCounter)
        : m_fpsCounter(fpsCounter), m_currentButton(0),
          m_buttons() {
    m_buttons.build("MainMenu/menu_bg.png", {0.f, 0.f});
    m_buttons.build("MainMenu/newgame_button.png", {360, 200});
    m_buttons.build("MainMenu/load_button.png", {360, 320});
    m_buttons.build("MainMenu/exit_button.png", {360, 440});
    m_numberOfButtons = 3;
}

void MenuScene::render(const RenderManager& renderer) {
    renderer.refresh(sf::Color{153, 204, 255});
    for (const auto& button : m_buttons.sprites()) {
        renderer.loadSprite(button);
    }
    sf::RectangleShape indicator({548, 96});
    indicator.setFillColor(sf::Color{255, 255, 255, 80});
    indicator.setPosition({360.f, 200.f + 120 * m_currentButton});
    renderer.drawSFML(indicator);
}

void MenuScene::update() {}

void MenuScene::handleEvents(sf::RenderWindow& window) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                switch (m_currentButton) {
                    case 0:
                        hasFinished = true;
                        break;
                    case 2:
                        window.close();
                        break;
                    default:
                        break;
                }
            } else if (event.key.code == sf::Keyboard::W) {
                m_currentButton = --m_currentButton < 0 ? char(m_numberOfButtons-1) : m_currentButton;
            } else if (event.key.code == sf::Keyboard::S) {
                m_currentButton = ++m_currentButton > char(m_numberOfButtons-1) ? char(0) : m_currentButton;
            }
        }
    }
}

const std::string MenuScene::nextScene() const {
    return "GameScene";
}
