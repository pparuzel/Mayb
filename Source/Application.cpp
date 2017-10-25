#include "Application.hpp"

Application::Application(const Config& config)
        : m_renderer(m_window), m_config(config) {

    m_fpsCounter = std::make_unique<FPSCounter>();
    m_scene = std::make_unique<SplashScreen>(config, *m_fpsCounter);
    m_window.create(sf::VideoMode(config.width, config.height), "Mayb2D");
    m_window.setFramerateLimit(config.fps_cap);
    m_window.setVerticalSyncEnabled(config.isVSyncOn);
}

void Application::handleEvents() {
    sf::Event event{};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}

void Application::run() {
    while (m_window.isOpen()) {
        handleEvents();
        m_fpsCounter->update();
        m_scene->update();

        m_window.clear(sf::Color::Black);
        m_scene->render(m_renderer);
        m_fpsCounter->draw(m_renderer);
        m_window.display();
        if (m_scene->closed())
            changeScene();
    }
}

void Application::changeScene() {
    Scene* scene_ptr = nullptr;
    if      (m_scene->nextScene() == "GameScene")
        scene_ptr = new GameScene(m_config, *m_fpsCounter);
    else if (m_scene->nextScene() == "MenuScene")
        scene_ptr = new MenuScene(m_config, *m_fpsCounter);
    else if (m_scene->nextScene() == "Exit")
        m_window.close();
    else throw "Wrong classname!\n";
    m_scene.reset(scene_ptr);
}
