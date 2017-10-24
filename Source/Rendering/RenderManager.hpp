#ifndef MAYBSFML_RENDERMANAGER_HPP
#define MAYBSFML_RENDERMANAGER_HPP


#include <SFML/Graphics.hpp>
#include "../World/Objects/Block.hpp"
#include "../Entity.hpp"


class RenderManager {
    sf::RenderWindow& m_window;
public:
    explicit RenderManager(sf::RenderWindow& window);

    void drawSFML(const sf::Drawable& drawable) const;

    void drawBlock(const Block& block) const;

    void drawEntity(Entity& entity) const;

    void loadSplash(const sf::Sprite&) const;

    void refresh(sf::Color color) const;
};


#endif //MAYBSFML_RENDERMANAGER_HPP
