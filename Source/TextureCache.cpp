#include "TextureCache.hpp"

TextureCache& TextureCache::getInstance()
{
    static TextureCache _instance{};
    return _instance;
}

const sf::Texture* TextureCache::find(const std::string& name)
{
    const auto it = textures_.find(name);
    return it != textures_.end() ? &it->second : nullptr;
}

const sf::Texture& TextureCache::load(const std::string& name, const std_fs::path& path)
{
    const auto* foundTexture = find(name);
    if (foundTexture)
    {
        return textures_[name] = *foundTexture;
    }
    return textures_[name] = ResourceManager::load<sf::Texture>(path);
}

const sf::Texture& TextureCache::add(const std::string& name, const sf::Texture& texture)
{
    return textures_[name] = texture;
}
