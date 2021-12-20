#ifndef MAYBSFML_NOFUNCTION_HPP
#define MAYBSFML_NOFUNCTION_HPP

#include "../../Rendering/RenderManager.hpp"
#include "IFunctionState.hpp"
#include <SFML/Graphics.hpp>

class FunctionManager;

class NoFunction : public IFunctionState
{
public:
    explicit NoFunction(FunctionManager& fmref) { printf("NoFunction\n"); };

    void render(const RenderManager& renderer) override;

    void mousePressed(int posx, int posy) override;

    void mouseMoved(int posx, int posy) override;
};

#endif  // MAYBSFML_NOFUNCTION_HPP
