#include "Utils/SpriteBuilder.hpp"

#include "TextureCache.hpp"

void SpriteBuilder::build(const std_fs::path& imagepath, const sf::Vector2f& position)
{
    sf::Sprite sprite;
    sprite.setTexture(TextureCache::getInstance().load(imagepath, imagepath));
    sprite.setPosition(position);
    sprites_.emplace_back(sprite);
    positions_.push_back(position);
}

const std::vector<sf::Sprite>& SpriteBuilder::sprites() const
{
    return sprites_;
}
