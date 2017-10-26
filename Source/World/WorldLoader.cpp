#include "WorldLoader.hpp"

WorldLoader::WorldLoader(const Config& config_ref)
        : m_entities(), config(config_ref), m_tiles() {
    m_tiles.loadFromFile("../Resources/World/tiles.png");
}

// TODO Blocks take only one reference to e.g. Grass Texture
void WorldLoader::load(std::string filepath, std::shared_ptr<Player>& p) {
    filepath = "../Resources/Maps/" + filepath;
    std::ifstream mapFile(filepath);
    if(!mapFile.is_open()) {
        std::cerr << "Error: Could not load map file!";
        return;
    }
    std::string c;
    float x, y, z;
    int s1, s2;
    std::string cmd;
    while (mapFile >> cmd) {
        if (cmd == "spawn") {
            mapFile >> c >> x >> y;
            p.reset(new Player({x, y}));
            m_entities.push_back(p);
            continue;
        }
        mapFile >> c;
        if (c == "from") {
            mapFile >> x >> y >> c >> z >> s1 >> s2;
            for(int i = 0; i < z; i++) {
                sf::Vector2f block_position = {x + s1 * i, y};
                sf::Vector2i block_size = {s1, s2};
                sf::Vector2i block_offset;
                if      (cmd == "dirt") block_offset = {576, 864};
                else if (cmd == "grass") block_offset = {504, 576};
                else if (cmd == "grassround") block_offset = {648, 0};
                else if (cmd == "cloud") block_offset = {0, 0};
//                else if (cmd == "sth") block_offset = {0, 0};
                m_blocks.push_back(std::make_shared<Block>(
                        m_tiles, block_position, block_size, block_offset));
            }
        }

    }

    mapFile.close();
}

void WorldLoader::reload(std::string filename) {
// TODO Reload method
    m_blocks.clear();
//    load(std::move(filename), ?);
}

