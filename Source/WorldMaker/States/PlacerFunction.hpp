#ifndef MAYBSFML_PLACERFUNCTION_HPP
#define MAYBSFML_PLACERFUNCTION_HPP

#include "../Button.hpp"
#include "IFunctionState.hpp"

class FunctionManager;

class PlacerFunction : public IFunctionState
{
    Button pinned_;
    FunctionManager& manager_;
    sf::RectangleShape indicator_;

public:
    explicit PlacerFunction(FunctionManager& fmref);

    void render(const RenderManager& renderer) override;

    void mousePressed(int posx, int posy) override;

    void mouseMoved(int posx, int posy) override;
};

#endif  // MAYBSFML_PLACERFUNCTION_HPP
