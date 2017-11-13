#ifndef MAYBSFML_BUTTONS_HPP
#define MAYBSFML_BUTTONS_HPP


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class SpriteBuilder {
    std::vector<sf::Sprite>     m_sprites;
    std::vector<sf::Vector2f>   m_positions;
public:
    SpriteBuilder();

    void build(std::string imagepath, const sf::Vector2f& position);

    const std::vector<sf::Sprite>& sprites() const;
};


#endif //MAYBSFML_BUTTONS_HPP
