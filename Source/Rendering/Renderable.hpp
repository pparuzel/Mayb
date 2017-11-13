#ifndef MAYBSFML_RENDERABLE_HPP
#define MAYBSFML_RENDERABLE_HPP


#include <SFML/Graphics.hpp>

class Renderable {
protected:
    sf::Texture*    m_texture;
    sf::Texture*    m_texture_mirror;
    sf::IntRect     m_indicator;
    sf::Sprite      m_sprite;
public:
    explicit Renderable(sf::Vector2i offset, sf::Vector2i size);

    const sf::Sprite& sprite() const;

    virtual ~Renderable() = default;
};


#endif //MAYBSFML_RENDERABLE_HPP
