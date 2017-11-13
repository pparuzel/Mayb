#include "TextureLoader.hpp"

TextureLoader::TextureLoader() : m_textures() {}

TextureLoader& TextureLoader::instance() {
    static TextureLoader _instance;

    return _instance;
}

sf::Texture* TextureLoader::get(const std::string& name) {
    return &m_textures.find(name)->second;
}

sf::Texture* TextureLoader::add(const std::string& name, const std::string& path) {
    sf::Texture temp;
    temp.loadFromFile(path);
    return &(m_textures[name] = temp);
}

sf::Texture* TextureLoader::add(const std::string& name, const sf::Texture& texture) {
    return &(m_textures[name] = texture);
}
