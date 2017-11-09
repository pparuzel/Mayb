#ifndef MAYBSFML_PLACERFUNCTION_HPP
#define MAYBSFML_PLACERFUNCTION_HPP


#include "IFunctionState.hpp"
#include "../Button.hpp"

class FunctionManager;

class PlacerFunction : public IFunctionState {
    Button              m_pinned;
    FunctionManager&    m_manager;
    sf::RectangleShape  m_indicator;
public:
    explicit PlacerFunction(FunctionManager& fmref);

    void render(const RenderManager& renderer) override;

    void mousePressed(int posx, int posy) override;

    void mouseMoved(int posx, int posy) override;
};


#endif //MAYBSFML_PLACERFUNCTION_HPP
