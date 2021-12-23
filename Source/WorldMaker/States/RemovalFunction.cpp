#include <iostream>
#include "RemovalFunction.hpp"
#include "FunctionManager.hpp"

RemovalFunction::RemovalFunction(FunctionManager& fmref) : m_manager(fmref), m_indicator({70, 70}) {
    m_indicator.setFillColor({100, 255, 100, 127});
    m_lastMousePos = {35, 175};
    printf("RemovalFunction\n");
}

void RemovalFunction::render(const RenderManager& renderer) {
    sf::FloatRect rect({static_cast<float>(m_lastMousePos.x-5), static_cast<float>(m_lastMousePos.y-5)}, {10, 10});
    auto it = m_manager.detectBlock(rect);
    sf::Vector2f pos;
    if (it == m_manager.blocksEnd()) {
        pos.x = m_lastMousePos.x-35;
        pos.y = m_lastMousePos.y-35;
    } else {
        pos = it->getPosition();
    }
    if (pos.y < 140) { pos.y = 140; }
    m_indicator.setPosition({pos.x, pos.y});
    renderer.drawSFML(m_indicator);
}

void RemovalFunction::mousePressed(int posx, int posy) {
    auto block = m_manager.detectBlock(m_indicator.getGlobalBounds());
    if (block != m_manager.blocksEnd()) {
        m_manager.removeBlock(block);
    }
}

void RemovalFunction::mouseMoved(int posx, int posy) {
    m_lastMousePos = {posx, posy};
}
