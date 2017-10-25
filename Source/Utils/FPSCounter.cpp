#include "FPSCounter.hpp"

FPSCounter::FPSCounter()
        : m_fpsTimer(), m_currentFrames(0), m_fps(0), m_tickTimer(), m_lastTick(0) {
    m_text.move(10, 10);
    m_text.setOutlineColor(sf::Color::Blue);
    m_text.setOutlineThickness(2);
    m_font.loadFromFile("../Resources/Fonts/arial_bold.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(25);
}

float slotTime = .5f;

void FPSCounter::update() {
    m_currentFrames++;

    if (m_fpsTimer.getElapsedTime().asSeconds() > slotTime) {
        m_fps = m_currentFrames / m_fpsTimer.getElapsedTime().asSeconds();
        m_fpsTimer.restart();
        m_currentFrames = 0;
    }
    m_lastTick = m_tickTimer.restart().asSeconds();
}

void FPSCounter::draw(const RenderManager& renderer) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << m_fps;
    m_text.setString("FPS: " + ss.str());
    renderer.drawSFML(m_text);
}

float FPSCounter::frametime() const {
    return m_lastTick;
}
