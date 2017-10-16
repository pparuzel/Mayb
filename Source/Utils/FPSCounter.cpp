#include "FPSCounter.hpp"

FPSCounter::FPSCounter() : m_timer(), m_currentFrames(0), m_fps(0) {
    m_text.move(10, 10);
    m_text.setOutlineColor(sf::Color::Blue);
    m_text.setOutlineThickness(2);
    m_font.loadFromFile("../Resources/arial_bold.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(25);
}

float slotTime = .5f;

void FPSCounter::update() {
    m_currentFrames++;

    if (m_timer.getElapsedTime().asSeconds() > slotTime) {
        m_fps = m_currentFrames / m_timer.getElapsedTime().asSeconds();
        m_currentFrames = 0;
        m_timer.restart();
    }
}

void FPSCounter::draw(const RenderManager& renderer) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(10) << m_fps;
    m_text.setString("FPS: " + ss.str());
    renderer.drawSFML(m_text);
}