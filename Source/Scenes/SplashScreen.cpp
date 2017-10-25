#include "SplashScreen.hpp"

SplashScreen::SplashScreen(const Config& config, const FPSCounter& fpsCounter)
        : m_fpsCounter(fpsCounter), m_sprites(3), m_textures(3),
          m_counter(0), m_trans(0), m_direction(1) {
    sf::Texture tex1, tex2, tex3;
    sf::Sprite splash1, splash2, splash3;
    if (    !tex1.loadFromFile("../Resources/SplashScreen/splashscreen.png") ||
            !tex2.loadFromFile("../Resources/SplashScreen/splashscreen2.png") ||
            !tex3.loadFromFile("../Resources/SplashScreen/xd.png")) {
        std::cerr << "Could not load SplashScreen!\n";
        return;
    }
    m_textures[0] = tex1;
    m_textures[1] = tex2;
    m_textures[2] = tex3;
    m_sprites[0] = splash1;
    m_sprites[1] = splash2;
    m_sprites[2] = splash3;
    m_sprites[0].setTexture(m_textures[0]);
    m_sprites[0].setPosition(400, 300);
    m_sprites[1].setTexture(m_textures[1]);
    m_sprites[1].setPosition(1000, 700);
    m_sprites[2].setTexture(m_textures[2]);
    m_sprites[2].setPosition(150, 150);
}

void SplashScreen::update() {
    showLogo();
    if ((m_trans < 5 and m_direction == -1) or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        hasFinished = true;
    }
}

void SplashScreen::render(const RenderManager& renderer) {
    sf::Uint8 alpha = 0;
    if (m_trans > 150)
        alpha = static_cast<sf::Uint8>(m_trans * 255.f / precision - 150);
    m_sprites[0].setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(m_trans * 255.f / precision)));
    m_sprites[1].setColor(sf::Color(255, 255, 255, alpha));
    m_sprites[2].setColor(sf::Color(255, 255, 255, 0));
    if (m_direction == -1) { m_sprites[2].setColor(sf::Color(
                255, 255, 255, alpha)); }
    for (const auto& sprite : m_sprites) {
        renderer.loadSprite(sprite);
    }
}

void SplashScreen::showLogo() {
    m_counter += m_fpsCounter.frametime();
    if (m_counter < 1.5f)
        return;
    if (m_counter > transitionDelay) {
        if (m_trans == precision)
            m_direction *= -1;
        m_counter = 1.5f;
        m_trans += m_direction;
    }
}

const std::string SplashScreen::nextScene() const {
    return "MenuScene";
}
