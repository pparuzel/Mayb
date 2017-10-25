#include "MenuScene.hpp"

MenuScene::MenuScene(const Config& config, const FPSCounter& fpsCounter)
        : m_fpsCounter(fpsCounter), m_textures(), m_focusedButton() {
    m_textures.emplace_back();
    m_textures.emplace_back();
    m_textures[0].loadFromFile("../Resources/menu_bg.png");
    m_textures[1].loadFromFile("../Resources/newgame_button.png");
    for (bool& isfocused : m_focusedButton) {
        isfocused = false;
    }
    m_focusedButton[0] = true;
}

void MenuScene::render(const RenderManager& renderer) {
    renderer.refresh(sf::Color{153, 204, 255});
    renderer.loadSprite(sf::Sprite(m_textures[0]));
    sf::Sprite tmp;
    tmp.setPosition(360, 200);
    tmp.setTexture(m_textures[1]);
    renderer.loadSprite(tmp);
}

void MenuScene::update() {
    if (m_focusedButton[0] and sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        hasFinished = true;
    }
}

const std::string MenuScene::nextScene() const {
    return "GameScene";
}