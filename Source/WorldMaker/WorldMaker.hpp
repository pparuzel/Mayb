#ifndef MAYBSFML_WORLDMAKER_HPP
#define MAYBSFML_WORLDMAKER_HPP


#include <SFML/Graphics.hpp>
#include "../Config.hpp"
#include "../Rendering/RenderManager.hpp"
#include "../Utils/Stash.hpp"
#include "Button.hpp"

class WorldMaker {
    sf::RenderWindow        m_window;
    RenderManager           m_renderer;
    Stash                   m_stash;
    std::vector<Button>     m_buttons;
    std::string pinned{""};
    sf::Vector2f buttonPos{0, 0};
public:
    explicit WorldMaker(const Config& config) : m_window(), m_renderer(m_window) {
        m_window.create(sf::VideoMode(config.width, config.height), "Mayb2D World Maker");
        m_window.setFramerateLimit(config.fps_cap);
        m_window.setVerticalSyncEnabled(config.isVSyncOn);
        setupTools();
    }

    void render() {
        for (const sf::Sprite& item : m_buttons) {
            m_renderer.loadSprite(item);
        }
        if (not pinned.empty()) {
            auto temp = m_stash.getSprite(pinned);
            temp.setPosition(buttonPos);
            m_renderer.loadSprite(temp);
        }
    }

    void run() {
        while (m_window.isOpen()) {
            sf::Event event{};
            while (m_window.pollEvent(event)) {
                if (event.type == event.Closed) { m_window.close(); }
                if (event.type == event.MouseButtonPressed) {
                    const auto& id = buttonClickedID(event.mouseButton.x, event.mouseButton.y);
                    pinned = id;
                    buttonPos = sf::Vector2f(event.mouseButton.x-35, event.mouseButton.y-35);
                }
                if (not pinned.empty() and event.type == event.MouseMoved) {
                    buttonPos = sf::Vector2f(event.mouseMove.x-35, event.mouseMove.y-35);
                }
            }

            m_window.clear(sf::Color{153, 204, 255});
            render();
            m_window.display();
        }
    }
private:
    void setupTools() {
        m_stash.add("dirt_lrrl", {0, 0});
        m_stash.add("dirt_llll", {0, 70});
        int i = 0;
        for (const auto& e : m_stash.data()) {
            sf::IntRect rect({e.second.x, e.second.y}, {70, 70});
            Button b(m_stash, e.first);
            b.setPosition(240 + 90*i, 20);
            m_buttons.push_back(std::move(b));
            ++i;
        }
    }

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
