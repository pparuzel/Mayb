#ifndef MAYBSFML_WORLDMAP_HPP
#define MAYBSFML_WORLDMAP_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include "Blocks/Block.hpp"
#include "../Config.hpp"

class WorldMap {
    std::vector<Block> m_blocks;
    const Config& config;
public:
    WorldMap(const Config&);

    void load(std::string filename);
};


#endif //MAYBSFML_WORLDMAP_HPP
