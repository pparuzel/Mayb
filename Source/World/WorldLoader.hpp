#ifndef MAYBSFML_WORLDMAP_HPP
#define MAYBSFML_WORLDMAP_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include "Blocks/Block.hpp"
#include "../Config.hpp"
#include "../Entity.hpp"

class WorldLoader {
protected:
    std::vector<Block> m_blocks;
    std::vector<Entity> m_entities;
    const Config& config;
public:
    WorldLoader(const Config&);

    void load(std::string filename);

    void reload(std::string filename);
};


#endif //MAYBSFML_WORLDMAP_HPP
