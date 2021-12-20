#ifndef MAYBSFML_REMOVALFUNCTION_HPP
#define MAYBSFML_REMOVALFUNCTION_HPP

#include "IFunctionState.hpp"

class FunctionManager;

class RemovalFunction : public IFunctionState
{
    FunctionManager& manager_;
    sf::RectangleShape indicator_;
    sf::Vector2i lastMousePos_;

public:
    explicit RemovalFunction(FunctionManager& fmref);

    void render(const RenderManager& renderer) override;

    void mousePressed(int posx, int posy) override;

    void mouseMoved(int posx, int posy) override;
};

#endif  // MAYBSFML_REMOVALFUNCTION_HPP
