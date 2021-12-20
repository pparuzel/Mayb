#include "PopUpMenu.hpp"

#include "Scenes/Scene.hpp"

PopUpMenu::PopUpMenu()
{
    buttons_.build("MainMenu/resumepop.png", {440, 120});
    buttons_.build("MainMenu/savepop.png", {440, 260});
    buttons_.build("MainMenu/loadpop.png", {440, 400});
    buttons_.build("MainMenu/return.png", {440, 540});
}

bool PopUpMenu::isOpen() const
{
    return isOpen_;
}

void PopUpMenu::toggle()
{
    isOpen_ = !isOpen_;
}

void PopUpMenu::update(sf::RenderWindow& window, Scene& parentScene)
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Enter)
            {
                switch (currentButton_)
                {
                    case 0: toggle(); break;
                    case 1: break;
                    case 3: parentScene.endScene(); break;
                    default: break;
                }
            }
            else if (event.key.code == sf::Keyboard::W)
            {
                currentButton_ = --(currentButton_) < 0 ? char(buttons_.sprites().size() - 1)
                                                        : currentButton_;
            }
            else if (event.key.code == sf::Keyboard::S)
            {
                currentButton_ = ++(currentButton_) > char(buttons_.sprites().size() - 1)
                                     ? char(0)
                                     : currentButton_;
            }
            else if (event.key.code == sf::Keyboard::Escape)
            {
                toggle();
            }
        }
    }
}

void PopUpMenu::render(const RenderManager& renderer)
{
    sf::RectangleShape rect({400, 570});
    rect.setFillColor(sf::Color{50, 100, 255, 50});
    rect.setPosition({430, 110});
    renderer.drawSFML(rect);
    for (const sf::Sprite& sprite : buttons_.sprites())
    {
        renderer.drawSFML(sprite);
    }
    sf::RectangleShape indicator({380, 133});
    indicator.setFillColor(sf::Color{255, 255, 255, 80});
    indicator.setPosition({440.f, 120.f + 140.f * currentButton_});
    renderer.drawSFML(indicator);
}
