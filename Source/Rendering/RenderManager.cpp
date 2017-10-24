#include "RenderManager.hpp"

RenderManager::RenderManager(sf::RenderWindow& window) : m_window(window) {}

void RenderManager::drawSFML(const sf::Drawable& drawable) const {
    m_window.draw(drawable);
}

void RenderManager::drawBlock(const Block& block) const {
    m_window.draw(block.sprite());
}

void RenderManager::drawEntity(Entity& entity) const {
    m_window.draw(entity.sprite());
}

void RenderManager::loadSplash(const sf::Sprite& s) const {
    m_window.clear(sf::Color::Black);
    m_window.draw(s);
}
