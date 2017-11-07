#include "PlacerFunction.hpp"
#include "FunctionManager.hpp"

PlacerFunction::PlacerFunction(FunctionManager& fmref)
        : functionManager(fmref), indicator({70, 70}) {
    indicator.setFillColor({100, 255, 100, 127});
    printf("PlacerFunction\n");
}

void PlacerFunction::mousePressed(int posx, int posy) {
    for (const sf::Sprite& item : functionManager.buttons()) {
        if (item.getGlobalBounds().contains(posx, posy)) {
            m_pinned = item;
            m_pinned.setPosition(0, 140);
            return;
        }
    }
    sf::Sprite b(m_pinned);
    posx -= posx % 35;
    posy -= posy % 35;
    b.setPosition(posx, posy);
    functionManager.addBlock(b);
}

void PlacerFunction::mouseMoved(int posx, int posy) {
    m_pinned.setPosition(posx, posy);
}
