#include "RenderManager.hpp"

RenderManager::RenderManager(sf::RenderWindow& window) : m_window(window) {}

void RenderManager::drawSFML(const sf::Drawable& drawable) const {
    m_window.draw(drawable);
}

void RenderManager::drawBlock(const Block& block) const {
    sf::IntRect rect(sf::Vector2i(block.offset), sf::Vector2i(70, 70));
    sf::Sprite sprite(Block::tiles, rect);
    sprite.setPosition(block.position.toSFML());
    m_window.draw(sprite);
}

void RenderManager::drawEntity(Entity& entity) const {
    entity.sprite.setTextureRect(entity.rect);
    entity.sprite.setPosition(entity.position.toSFML());
    m_window.draw(entity.sprite);
}