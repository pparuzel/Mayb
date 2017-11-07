#include "RenderManager.hpp"

RenderManager::RenderManager(sf::RenderWindow& window) : m_window(window) {}

void RenderManager::drawSFML(const sf::Drawable& drawable) const {
    m_window.draw(drawable);
}

void RenderManager::drawSFML(const sf::Vertex* vertices, size_t vertexCount, sf::PrimitiveType p) const {
    m_window.draw(vertices, vertexCount, p);
}

void RenderManager::drawBlock(const Block& block) const {
    m_window.draw(block.sprite());
}

void RenderManager::drawEntity(Entity& entity) const {
    m_window.draw(entity.sprite());
}

void RenderManager::loadSprite(const sf::Sprite& s) const {
    m_window.draw(s);
}

void RenderManager::refresh(sf::Color color) const {
    m_window.clear(color);
}
