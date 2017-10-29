#ifndef MAYBSFML_WORLDMAKER_HPP
#define MAYBSFML_WORLDMAKER_HPP


#include <SFML/Graphics.hpp>
#include "../Config.hpp"

class WorldMaker {
    sf::RenderWindow m_window;
public:
    explicit WorldMaker(const Config& config) : m_window() {
        m_window.create(sf::VideoMode(config.width, config.height), "Mayb2D World Maker");
        m_window.setFramerateLimit(config.fps_cap);
        m_window.setVerticalSyncEnabled(config.isVSyncOn);
    }

    void run() {
        while (m_window.isOpen()) {
            sf::Event event{};
            while (m_window.pollEvent(event)) {
                if (event.type == event.Closed) { m_window.close(); }
            }

            m_window.clear(sf::Color{153, 204, 255});
            m_window.display();
        }
    }
};


#endif //MAYBSFML_WORLDMAKER_HPP
