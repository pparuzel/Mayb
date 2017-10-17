#include "Application.hpp"

Application::Application(const Config& config)
        : m_fpsCounter(), m_renderer(m_window), m_scene(std::make_unique<GameScene>(config)), m_config(config) {

    m_window.create(sf::VideoMode(config.width, config.height), "Mayb as Always");
    m_window.setFramerateLimit(config.fps_cap);
}

void Application::handleEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}

void Application::run() {
    while (m_window.isOpen()) {
        handleEvents();
        m_fpsCounter.update();
        // Scene handling
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//            m_scene->generate();
//        }


        m_window.clear(sf::Color::Black);
        m_scene->render(m_renderer);
        m_fpsCounter.draw(m_renderer);
        m_window.display();
    }
}