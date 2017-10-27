#ifndef MAYBSFML_POPUPMENU_HPP
#define MAYBSFML_POPUPMENU_HPP


#include <SFML/Graphics.hpp>
#include "../Rendering/RenderManager.hpp"
#include "../Utils/SpriteBuilder.hpp"

class PopUpMenu {
    bool m_isOpen;
    SpriteBuilder m_buttons;
public:
    PopUpMenu() : m_isOpen(false) {
        m_buttons.build("MainMenu/return.png", {440, 260});
    }

    bool isOpen() const {
        return m_isOpen;
    }

    void toggle() {
        m_isOpen = !m_isOpen;
    }

    void render(const RenderManager& renderer) {
        sf::RectangleShape rect({400, 150});
        rect.setFillColor(sf::Color{50, 100, 255, 30});
        rect.setPosition(430, 250);
        renderer.drawSFML(rect);
        for (const sf::Sprite& sprite : m_buttons.sprites()) {
            renderer.drawSFML(sprite);
        }
    }
};


#endif //MAYBSFML_POPUPMENU_HPP
