#ifndef MAYBSFML_RENDERABLE_HPP
#define MAYBSFML_RENDERABLE_HPP

#include <SFML/Graphics.hpp>

class Renderable
{
protected:
    const sf::Texture* texture_;
    const sf::Texture* texture_mirror_;
    sf::IntRect indicator_;
    sf::Sprite sprite_;

public:
    explicit Renderable(sf::Vector2i offset, sf::Vector2i size);

    const sf::Sprite& sprite() const;

    virtual ~Renderable() = default;
};

#endif  // MAYBSFML_RENDERABLE_HPP
