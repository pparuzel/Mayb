#include "PopUpMenu.hpp"

PopUpMenu::PopUpMenu() {
    m_buttons.build("MainMenu/resumepop.png", {440, 120});
    m_buttons.build("MainMenu/savepop.png", {440, 260});
    m_buttons.build("MainMenu/loadpop.png", {440, 400});
    m_buttons.build("MainMenu/return.png", {440, 540});
}

bool PopUpMenu::isOpen() const {
    return m_isOpen;
}

void PopUpMenu::toggle() {
    m_isOpen = !m_isOpen;
}

void PopUpMenu::update(sf::RenderWindow& window, bool& requestClose) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            requestClose = true;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Return) {
                switch (m_currentButton) {
                    case 0:
                        toggle();
                        break;
                    case 1:
                        break;
                    case 3:
                        requestClose = true;
                        break;
                    default:
                        break;
                }
            } else if (event.key.code == sf::Keyboard::W) {
                m_currentButton = --(m_currentButton) < 0 ? char(m_buttons.sprites().size() - 1) : m_currentButton;
            } else if (event.key.code == sf::Keyboard::S) {
                m_currentButton =
                        ++(m_currentButton) > char(m_buttons.sprites().size() - 1) ? char(0) : m_currentButton;
            } else if (event.key.code == sf::Keyboard::Escape) {
                toggle();
            }
        }
    }
}

void PopUpMenu::render(const RenderManager& renderer) {
    sf::RectangleShape rect({400, 570});
    rect.setFillColor(sf::Color{50, 100, 255, 50});
    rect.setPosition(430, 110);
    renderer.drawSFML(rect);
    for (const sf::Sprite& sprite : m_buttons.sprites()) {
        renderer.drawSFML(sprite);
    }
    sf::RectangleShape indicator({380, 133});
    indicator.setFillColor(sf::Color{255, 255, 255, 80});
    indicator.setPosition(440, 120 + 140 * m_currentButton);
    renderer.drawSFML(indicator);
}
