#ifndef MAYBSFML_PLACERFUNCTION_HPP
#define MAYBSFML_PLACERFUNCTION_HPP


#include <SFML/Graphics/Sprite.hpp>
#include "IFunctionState.hpp"

class FunctionManager;

class PlacerFunction : public IFunctionState {
    sf::Sprite m_pinned;
    FunctionManager& functionManager;
    sf::RectangleShape indicator;
public:
    explicit PlacerFunction(FunctionManager& fmref);

    void render(const RenderManager& renderer) override {
        auto pos = m_pinned.getPosition();
        pos.x -= static_cast<int>(pos.x) % 35;
        pos.y -= static_cast<int>(pos.y) % 35;
        indicator.setPosition(pos.x, pos.y);
        renderer.drawSFML(indicator);
        renderer.loadSprite(m_pinned);
    }

    void mousePressed(int posx, int posy) override;

    void mouseMoved(int posx, int posy) override;
};


#endif //MAYBSFML_PLACERFUNCTION_HPP
