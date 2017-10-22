#include "WorldLoader.hpp"

WorldLoader::WorldLoader(const Config& config_ref)
        : m_entities(), config(config_ref) {}

void WorldLoader::load(std::string filename, std::shared_ptr<Player> p) {
    std::ifstream mapFile(filename);
    if(!mapFile.is_open()) {
        std::cerr << "Error: Could not load map file!";
        return;
    }
    std::string c;
    float x, y, z, s1, s2;
    std::string cmd;
    while (mapFile >> cmd) {
        if (cmd == "spawn") {
            mapFile >> c >> x >> y;
            p->position = {x, y};
            m_entities.push_back(p);
            continue;
        }
        mapFile >> c;
        if (c == "from") {
            mapFile >> x >> y >> c >> z >> s1 >> s2;
            for(float i = 0; i < z; i++) {
                std::shared_ptr<Block> block = std::make_shared<Block>();
                block->position = {x + s1 * i, y};
                block->size = {s1, s2};
                if      (cmd == "dirt") block->offset = {576, 864};
                else if (cmd == "grass") block->offset = {504, 576};
                else if (cmd == "grassround") block->offset = {648, 0};
                else if (cmd == "cloud") block->offset = {0, 0};
//                else if (cmd == "sth") block->offset = {0, 0};
                m_blocks.push_back(block);
            }
        }

    }

    mapFile.close();
//    std::ifstream mapFile(filename);
//
//    if(!mapFile.is_open()) {
//        std::cerr << "Error: Could not load map file!";
//        return;
//    }
//    char c;
//    int spaces = 0;
//    int newlines = 1;
//    int square_height = -2;
//    int square_width = 0;
//    std::string line;
//    for (; std::getline(mapFile, line); ++square_height);
//    mapFile.clear();
//    mapFile.seekg(0, mapFile.beg);
//    std::getline(mapFile, line);
//    square_width = static_cast<int>(line.size());
//    float real_width = static_cast<float>(config.width) / square_width;
//    float real_height = static_cast<float>(config.height) / square_height;
//    bool eofile = false;
//
//    while (mapFile >> std::noskipws >> c && !eofile) {
//        if (c == ' ' || c == '\n' || c == 'P') {
//            ++spaces;
//            if (c == 'P' && p != nullptr) {
//                p->position = {spaces * real_width, (newlines - 1) * real_height};
//                m_entities.push_back(p);
//            } else if (c == '\n') {
//                spaces = 0;
//                ++newlines;
//            }
//        } else if (c == 'x') {
//            std::shared_ptr<Block> block = std::make_shared<Block>();
//            block->size = {real_width, real_height};
//            block->position = {spaces * real_width, (newlines - 1) * real_height};
//            m_blocks.push_back(block);
//            spaces += 1;
//        } else if (c == '-') {
//            eofile = true;
//        }
//    }
//    mapFile.close();
}

void WorldLoader::reload(std::string filename) {
    m_blocks.clear();
    load(filename, nullptr);
}
