#include "RenderManager.hpp"

RenderManager::RenderManager(sf::RenderWindow& window) : m_window(window) {}

void RenderManager::drawSFML(const sf::Drawable& drawable) const {
    m_window.draw(drawable);
}
