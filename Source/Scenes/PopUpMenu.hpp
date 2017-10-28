#ifndef MAYBSFML_POPUPMENU_HPP
#define MAYBSFML_POPUPMENU_HPP


#include <SFML/Graphics.hpp>
#include "../Rendering/RenderManager.hpp"
#include "../Utils/SpriteBuilder.hpp"

class PopUpMenu {
    SpriteBuilder   m_buttons{};
    signed char     m_currentButton{0};
    bool            m_isOpen{false};
public:
    explicit PopUpMenu();

    bool isOpen() const;

    void toggle();

    void render(const RenderManager& renderer);

    void update(sf::RenderWindow& window, bool& requestClose);
};


#endif //MAYBSFML_POPUPMENU_HPP
