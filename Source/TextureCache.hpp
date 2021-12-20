#ifndef MAYBSFML_TEXTURELOADER_HPP
#define MAYBSFML_TEXTURELOADER_HPP

#include "Utils/ResourceManager.hpp"

#include <SFML/Graphics.hpp>

#include <array>
#include <functional>
#include <map>
#include <string>
#include <string_view>

class TextureCache
{
private:
    TextureCache() = default;

public:
    TextureCache(const TextureCache&) = delete;
    TextureCache& operator=(const TextureCache&) = delete;
    TextureCache(TextureCache&&) = delete;
    TextureCache& operator=(TextureCache&&) = delete;
    ~TextureCache() = default;

    static TextureCache& getInstance();
    const sf::Texture& add(const std::string& name, const sf::Texture& texture);
    const sf::Texture& fetch(const std::string& name, const std_fs::path& path);
    const sf::Texture* find(const std::string& name);

private:
    std::map<std::string, sf::Texture> textures_;
};

#endif  // MAYBSFML_TEXTURELOADER_HPP
