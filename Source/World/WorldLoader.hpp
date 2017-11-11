#ifndef MAYBSFML_WORLDLOADER_HPP
#define MAYBSFML_WORLDLOADER_HPP


#include <vector>
#include "Objects/Block.hpp"
#include "../Player/Player.hpp"
#include "../Config.hpp"
#include "../Entity.hpp"

class WorldLoader {
    const Config& config;
protected:
    std::vector<std::shared_ptr<Block>>     m_blocks;
    std::vector<std::shared_ptr<Entity>>    m_entities;
    sf::Texture                             m_tiles;
public:
    explicit WorldLoader(const Config&);

    void load(std::string filepath, std::shared_ptr<Player>&);

    void reload(std::string filepath);
};


#endif //MAYBSFML_WORLDLOADER_HPP
