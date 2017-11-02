#ifndef MAYBSFML_WORLDMAKER_HPP
#define MAYBSFML_WORLDMAKER_HPP


#include <SFML/Graphics.hpp>
#include "../Config.hpp"
#include "../Rendering/RenderManager.hpp"
#include "States/FunctionManager.hpp"
#include "Button.hpp"

class WorldMaker {
    sf::RenderWindow        m_window;
    FunctionManager         m_functionManager;
    RenderManager           m_renderer;
    std::vector<Button>     m_buttons;

public:
    explicit WorldMaker(const Config& config)
            : m_window(), m_renderer(m_window), m_functionManager() {
        m_window.create(sf::VideoMode(config.width, config.height), "Mayb2D World Maker");
        m_window.setFramerateLimit(config.fps_cap);
        m_window.setVerticalSyncEnabled(config.isVSyncOn);
    }

    void run() {
        while (m_window.isOpen()) {
            m_window.clear(sf::Color{153, 204, 255});
            m_functionManager.handleEvents(m_window);
            m_functionManager.render(m_renderer);
            m_window.display();
        }
    }
private:
    std::string buttonClickedID(int posx, int posy) {
        for (const auto& b : m_buttons) {
            if (b.getGlobalBounds().contains(posx, posy)) {
                return b.getID();
            }
        }
        return "";
    }
};


#endif //MAYBSFML_WORLDMAKER_HPP