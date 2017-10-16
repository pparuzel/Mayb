#ifndef MAYBSFML_RENDERMANAGER_HPP
#define MAYBSFML_RENDERMANAGER_HPP


#include <SFML/Graphics.hpp>

class RenderManager {
    sf::RenderWindow& m_window;
public:
    RenderManager(sf::RenderWindow& window);

    void drawSFML(const sf::Drawable& drawable) const;
};


#endif //MAYBSFML_RENDERMANAGER_HPP
