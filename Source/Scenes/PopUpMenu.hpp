#ifndef MAYBSFML_POPUPMENU_HPP
#define MAYBSFML_POPUPMENU_HPP

#include "Rendering/RenderManager.hpp"
#include "Utils/SpriteBuilder.hpp"

#include <SFML/Graphics.hpp>

// Forward declarations
struct Scene;

class PopUpMenu
{
    SpriteBuilder buttons_{};
    signed char currentButton_{0};
    bool isOpen_{false};

public:
    explicit PopUpMenu();
    bool isOpen() const;
    void toggle();
    void render(sf::RenderWindow& renderer);
    void update(sf::RenderWindow& window, bool& isRunning);
};

#endif  // MAYBSFML_POPUPMENU_HPP
