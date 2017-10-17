#include "RenderManager.hpp"

RenderManager::RenderManager(sf::RenderWindow& window) : m_window(window) {}

void RenderManager::drawSFML(const sf::Drawable& drawable) const {
    m_window.draw(drawable);
}

void RenderManager::drawBlock(const Block& block) const {
    sf::RectangleShape rect(block.size.toSFML());
    rect.setPosition(block.position.toSFML());
    m_window.draw(rect);
}

void RenderManager::drawEntity(const Entity& entity) const {
    sf::RectangleShape rect({50, 100});
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition(entity.getPosition().toSFML());
    m_window.draw(rect);
}