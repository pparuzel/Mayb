#ifndef MAYBSFML_NOFUNCTION_HPP
#define MAYBSFML_NOFUNCTION_HPP


#include <SFML/Graphics.hpp>
#include "IFunctionState.hpp"
#include "../../Rendering/RenderManager.hpp"

class FunctionManager;

class NoFunction : public IFunctionState {
public:
    explicit NoFunction(FunctionManager& fmref) {
        printf("NoFunction\n");
    };

    void render(const RenderManager& renderer) override;

    void mousePressed(int posx, int posy) override;

    void mouseMoved(int posx, int posy) override;
};


#endif //MAYBSFML_NOFUNCTION_HPP
