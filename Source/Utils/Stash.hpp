#ifndef MAYBSFML_TEXTURESTASH_HPP
#define MAYBSFML_TEXTURESTASH_HPP


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <map>
#include "../TextureLoader.hpp"

class Stash {
    sf::Texture*                        m_tileset;
    std::map<std::string, sf::IntRect>  m_tileTypeMap;
public:
    Stash() {
        m_tileset = TextureLoader::instance().add("", "../Resources/World/tileset.png");
    }

    void add(const std::string& tileTypeName, int x, int y) {
        m_tileTypeMap.insert({tileTypeName, sf::IntRect(x, y, 70, 70)});
    }

    sf::Sprite getSprite(const std::string& tileTypeName) const {
        return sf::Sprite(*m_tileset, m_tileTypeMap.find(tileTypeName)->second);
    }

    const auto& data() const {
        return m_tileTypeMap;
    }
};


#endif //MAYBSFML_TEXTURESTASH_HPP
