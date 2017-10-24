#include "SplashScreen.hpp"

SplashScreen::SplashScreen(const Config& config, const FPSCounter& fpsCounter)
        : m_fpsCounter(fpsCounter), m_splash(), m_texture(), m_counter(0), m_trans(0) {
    if (!m_texture.loadFromFile("../Resources/splashscreen.png")) {
        std::cerr << "Could not load SplashScreen!\n";
        return;
    }
    m_splash.setTexture(m_texture);
    m_splash.setPosition(400, 300);
}

int direction = 1;

void SplashScreen::update() {
    m_counter += m_fpsCounter.frametime();
    if (m_counter < 1.5f)
        return;
    if (m_counter > transitionDelay) {
        if (m_trans == precision)
            direction *= -1;
        m_counter = 1.5f;
        m_trans += direction;
    }
    if (m_trans < 0) {
//        m_app.changeScene(std::make_unique<GameScene>())
    }
}

void SplashScreen::render(const RenderManager& renderer) {
    m_splash.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(m_trans * 255.f/precision)));
    renderer.loadSplash(m_splash);
}
