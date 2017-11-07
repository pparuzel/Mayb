#ifndef MAYBSFML_IFUNCTION_HPP
#define MAYBSFML_IFUNCTION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../../Rendering/RenderManager.hpp"

class IFunctionState {
protected:
    IFunctionState() = default;
public:
    virtual void render(const RenderManager& renderer) = 0;

    virtual void mousePressed(int posx, int posy) = 0;

    virtual void mouseMoved(int posx, int posy) = 0;

    virtual ~IFunctionState() = default;
};


#endif //MAYBSFML_IFUNCTION_HPP
