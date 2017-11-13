#include "SpriteBuilder.hpp"
#include "../TextureLoader.hpp"

SpriteBuilder::SpriteBuilder() : m_sprites(), m_positions() {}

void SpriteBuilder::build(std::string imagepath, const sf::Vector2f& position) {
    sf::Sprite sprite;
    m_sprites.emplace_back();
    imagepath = "../Resources/" + imagepath;
    m_sprites.back().setTexture(*TextureLoader::instance().add(imagepath, imagepath));
    m_sprites.back().setPosition(position);
    m_positions.push_back(position);
}

const std::vector<sf::Sprite>& SpriteBuilder::sprites() const {
    return m_sprites;
}
