#include "PlacerFunction.hpp"
#include "FunctionManager.hpp"

PlacerFunction::PlacerFunction(FunctionManager& fmref)
        : m_manager(fmref), m_indicator({70, 70}) {
    m_indicator.setFillColor({100, 255, 100, 127});
    printf("PlacerFunction\n");
}

void PlacerFunction::render(const RenderManager& renderer) {
    auto pos = m_pinned.getPosition();
    pos.x -= static_cast<int>(pos.x) % 35;
    pos.y -= static_cast<int>(pos.y) % 35;
    if (pos.y < 140) { pos.y = 140; }
    m_indicator.setPosition(pos.x, pos.y);
    renderer.drawSFML(m_indicator);
    renderer.loadSprite(m_pinned);
}

void PlacerFunction::mousePressed(int posx, int posy) {
    const sf::Sprite* button = m_manager.detectButton(posx, posy);
    if (button != nullptr) {
        m_pinned = *button;
        m_pinned.setPosition(0, 140);
        return;
    }
    //

    const sf::Sprite* block = m_manager.detectBlock(m_indicator.getGlobalBounds());
    if (posy < 140 || block != nullptr) { return; }
    sf::Sprite b(m_pinned);
    posx -= posx % 35;
    posy -= posy % 35;
    b.setPosition(posx, posy);
    m_manager.addBlock(b);
}

void PlacerFunction::mouseMoved(int posx, int posy) {
    m_pinned.setPosition(posx, posy);
}
