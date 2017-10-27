#include "SpriteBuilder.hpp"

SpriteBuilder::SpriteBuilder() : m_textures(), m_sprites(), m_positions() {}

void SpriteBuilder::build(std::string imagepath, const sf::Vector2f& position) {
    // Concurrency fails because of sprite.setTexture(m_textures.back());
    // TODO think of a better (concurrent) solution
    std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    sf::Sprite sprite;
    m_textures.push_back(std::move(texture));
    m_sprites.emplace_back();
    imagepath = "../Resources/" + imagepath;
    if (!m_textures.back()->loadFromFile(imagepath))
        throw "Could not load texture for the filepath!\n";
    m_sprites.back().setTexture(*m_textures.back());
    m_sprites.back().setPosition(position);
    m_positions.push_back(position);
}

const std::vector<sf::Sprite>& SpriteBuilder::sprites() {
    return m_sprites;
}
