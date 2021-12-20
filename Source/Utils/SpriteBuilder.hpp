#ifndef MAYBSFML_BUTTONS_HPP
#define MAYBSFML_BUTTONS_HPP

#include "Utils/ResourceManager.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class SpriteBuilder
{
    std::vector<sf::Sprite> sprites_;
    std::vector<sf::Vector2f> positions_;

public:
    SpriteBuilder() = default;

    void build(const std_fs::path& imagepath, const sf::Vector2f& position);

    const std::vector<sf::Sprite>& sprites() const;
};

#endif  // MAYBSFML_BUTTONS_HPP
