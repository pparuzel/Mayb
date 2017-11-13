#ifndef MAYBSFML_TEXTURELOADER_HPP
#define MAYBSFML_TEXTURELOADER_HPP

#include <string>
#include <map>
#include <SFML/Graphics.hpp>

/**
 *   ### C++11 Thread-safe Singleton ###
 *   also possible process-independent version:
 *      static std::shared_ptr<Singleton> s{new Singleton()};
 *   2017 (C) Pawel Paruzel
 */
class TextureLoader {
private:
    std::map<std::string, sf::Texture> m_textures;

    TextureLoader();
public:
    TextureLoader(const TextureLoader&)             = delete;
    TextureLoader& operator=(const TextureLoader&)  = delete;
    static TextureLoader& instance();

    sf::Texture* add(const std::string& name, const std::string& path);

    sf::Texture* add(const std::string& name, const sf::Texture& texture);

    sf::Texture* get(const std::string& name);
};


#endif //MAYBSFML_TEXTURELOADER_HPP
