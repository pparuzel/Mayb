#ifndef MAYBSFML_NOFUNCTION_HPP
#define MAYBSFML_NOFUNCTION_HPP


#include <SFML/Graphics.hpp>
#include "IFunctionState.hpp"
#include "../../Rendering/RenderManager.hpp"

class NoFunction : public IFunctionState {
    std::vector<sf::Sprite> m_sprites;
public:
    NoFunction() : m_sprites() {};

};


#endif //MAYBSFML_NOFUNCTION_HPP
