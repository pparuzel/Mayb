#ifndef MAYBSFML_TEXTURESTASH_HPP
#define MAYBSFML_TEXTURESTASH_HPP

#include "TextureCache.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <map>

class Stash
{
    const sf::Texture& tileset_ =
        TextureCache::getInstance().fetch("Stash.tileset",
                                          std_fs::path("World") / "tileset.png");
    std::map<std::string, sf::IntRect> tileTypeMap_;

public:
    void add(const std::string& tileTypeName, int x, int y)
    {
        tileTypeMap_.insert({tileTypeName, sf::IntRect(x, y, 70, 70)});
    }

    sf::Sprite getSprite(const std::string& tileTypeName) const
    {
        return {tileset_, tileTypeMap_.find(tileTypeName)->second};
    }

    const auto& data() const { return tileTypeMap_; }
};

#endif  // MAYBSFML_TEXTURESTASH_HPP
