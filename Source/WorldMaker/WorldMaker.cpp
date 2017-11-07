#include "WorldMaker.hpp"

WorldMaker::WorldMaker(const Config& config)
        : m_window(), m_renderer(m_window), m_functionManager() {
    m_window.create(sf::VideoMode(config.width, config.height + 140), "Mayb2D World Maker");
    m_window.setFramerateLimit(config.fps_cap);
    m_window.setVerticalSyncEnabled(config.isVSyncOn);
}

void WorldMaker::run() {
    while (m_window.isOpen()) {
        m_window.clear(sf::Color{153, 204, 255});
        m_functionManager.handleEvents(m_window);
        m_functionManager.render(m_renderer);
        m_window.display();
    }
}
