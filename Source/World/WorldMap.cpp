#include "WorldMap.hpp"


WorldMap::WorldMap(const Config& config_ref)
        : m_blocks(), config(config_ref) {}

void WorldMap::load(std::string filename) {
    std::ifstream mapFile(filename);

    if(!mapFile.is_open()) {
        std::cerr << "Error: Could not load map file!";
        return;
    }
    char c;
    float world_width = 0;
    float world_height = 0;
    float block_width = 0;

    while (mapFile >> c) {
        if (c == '-') {
            ++world_width;
        }
        else if (c == '\n') {
            ++world_height;
        }
        else if (c == '[' || c == '-') {
            if (c == '[') block_width = 0;
            ++block_width;
        }
        else if (c == ']') {
            Block block(block_width / config.width);
            m_blocks.push_back(block);
        }
        else {
            std::cerr << "Error: Wrong map content format!";
        }
    }
    for (auto b : m_blocks) {
        b.size.y = world_height / config.height;
    }
}
