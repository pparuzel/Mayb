#ifndef MAYBSFML_RENDERMANAGER_HPP
#define MAYBSFML_RENDERMANAGER_HPP

#include "../Entity.hpp"
#include "../World/Objects/Block.hpp"
#include <SFML/Graphics.hpp>

class RenderManager
{
    sf::RenderWindow& window_;

public:
    explicit RenderManager(sf::RenderWindow& window);

    void drawSFML(const sf::Drawable& drawable) const;

    void drawBlock(const Block& block) const;

    void drawEntity(Entity& entity) const;

    void loadSprite(const sf::Sprite&) const;

    void refresh(sf::Color color) const;

    void drawSFML(const sf::Vertex* vertices, size_t vertexCount, sf::PrimitiveType p) const;
};

#endif  // MAYBSFML_RENDERMANAGER_HPP
