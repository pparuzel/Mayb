#ifndef MAYBSFML_IFUNCTION_HPP
#define MAYBSFML_IFUNCTION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class IFunctionState {
protected:
    IFunctionState() = default;
public:

    virtual ~IFunctionState() = default;
};


#endif //MAYBSFML_IFUNCTION_HPP
