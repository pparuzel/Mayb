#include "RemovalFunction.hpp"
#include "FunctionManager.hpp"

RemovalFunction::RemovalFunction(FunctionManager& fmref) : m_manager(fmref), m_indicator({70, 70}) {
    m_indicator.setFillColor({100, 255, 100, 127});
    printf("RemovalFunction\n");
}

void RemovalFunction::render(const RenderManager& renderer) {
    auto posx = m_lastMousePos.x - m_lastMousePos.x % 35;
    auto posy = m_lastMousePos.y - m_lastMousePos.y % 35;
    if (posy < 140) { posy = 140; }
    m_indicator.setPosition(posx, posy);
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
