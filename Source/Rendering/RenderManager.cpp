#include "RenderManager.hpp"

RenderManager::RenderManager(sf::RenderWindow& window)
    : window_(window)
{
}

void RenderManager::drawSFML(const sf::Drawable& drawable) const
{
    window_.draw(drawable);
}

void RenderManager::drawSFML(const sf::Vertex* vertices,
                             size_t vertexCount,
                             sf::PrimitiveType p) const
{
    window_.draw(vertices, vertexCount, p);
}

void RenderManager::drawBlock(const Block& block) const
{
    window_.draw(block.sprite());
}

void RenderManager::drawEntity(Entity& entity) const
{
    window_.draw(entity.sprite());
}

void RenderManager::loadSprite(const sf::Sprite& s) const
{
    window_.draw(s);
}

void RenderManager::refresh(sf::Color color) const
{
    window_.clear(color);
}
