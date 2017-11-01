#ifndef MAYBSFML_TEXTURESTASH_HPP
#define MAYBSFML_TEXTURESTASH_HPP


#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <SFML/Graphics/Sprite.hpp>

class Stash {
    sf::Texture                         m_tileset;
    std::map<std::string, sf::Vector2i> m_tileTypeMap;
public:
    Stash() {
        m_tileset.loadFromFile("../Resources/World/tileset.png");
    }

    void add(const std::string& tileTypeName, sf::Vector2i&& tilePos) {
        m_tileTypeMap.insert({tileTypeName, tilePos});
    }

    sf::Sprite getSprite(const std::string& tileTypeName) const {
        const sf::Vector2i& tileRect = m_tileTypeMap.find(tileTypeName)->second;
        sf::IntRect rect(tileRect, {70, 70});
        return sf::Sprite(m_tileset, rect);
    }

    std::size_t size() {
        return m_tileTypeMap.size();
    }

    const auto& data() const {
        return m_tileTypeMap;
    }
};


#endif //MAYBSFML_TEXTURESTASH_HPP
