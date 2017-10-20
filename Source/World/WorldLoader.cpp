#include "WorldLoader.hpp"

WorldLoader::WorldLoader(const Config& config_ref)
        : m_entities(), config(config_ref) {}

void WorldLoader::load(std::string filename, std::shared_ptr<Player> p) {
    std::ifstream mapFile(filename);

    if(!mapFile.is_open()) {
        std::cerr << "Error: Could not load map file!";
        return;
    }
    char c;
    int spaces = 0;
    int newlines = 1;
    int square_height = -2;
    int square_width = 0;
    int block_width = 0;
    std::string line;
    for (; std::getline(mapFile, line); ++square_height);
    mapFile.clear();
    mapFile.seekg(0, mapFile.beg);
    std::getline(mapFile, line);
    square_width = static_cast<int>(line.size());
    float real_width = static_cast<float>(config.width) / square_width;
    float real_height = static_cast<float>(config.height) / square_height;
    bool eofile = false;

    while (mapFile >> std::noskipws >> c && !eofile) {
        if (c == ' ' || c == '\n' || c == 'P') {
            if (block_width > 0) {
                std::shared_ptr<Block> block = std::make_shared<Block>();
                block->size = {block_width * real_width, real_height};
                block->position = {spaces * real_width, (newlines - 1) * real_height};
                m_blocks.push_back(block);
                spaces += block_width;
                block_width = 0;
            }
            ++spaces;
            if (c == 'P' && p != nullptr) {
                p->position = {spaces * real_width, (newlines - 1) * real_height};
                m_entities.push_back(p);
            } else if (c == '\n') {
                spaces = 0;
                ++newlines;
            }
        } else if (c == 'x') {
            ++block_width;
        } else if (c == '-') {
            eofile = true;
        }
    }
    mapFile.close();
}

void WorldLoader::reload(std::string filename) {
    m_blocks.clear();
    load(filename, nullptr);
}
