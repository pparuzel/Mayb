#include "WorldLoader.hpp"
#include <iostream>
#include <cassert>

WorldLoader::WorldLoader(const Config& config_ref)
        : m_entities(), config(config_ref), m_tiles() {
    m_tiles.loadFromFile("../Resources/World/tiles.png");
}

// TODO Blocks take only one reference to e.g. Grass Texture

std::vector<std::string> split(const std::string& str, const std::string& delimiter=" ") {
    std::vector<std::string> words;
    std::string temp{};
    for (int i=0; i<=str.length(); ++i) {
        bool not_delimiter = true;
        for (int j=0; j<=delimiter.length(); ++j) {
            if (str[i] == delimiter[j]) {
                not_delimiter = false;
                break;
            }
        }
        if (not_delimiter) {
            temp += str[i];
        } else if (!temp.empty()) {
            words.push_back(temp);
            temp = "";
        }
    }
    return words;
}

void WorldLoader::load(std::string filepath, std::shared_ptr<Player>& p) {
    filepath = "../Resources/Maps/" + filepath;
    std::ifstream map(filepath);
    if (!map.is_open()) {
        std::cerr << "Error: Could not load map file!";
        return;
    }
    std::string line;
    while (std::getline(map, line)) {
        auto words = split(line, "[ ],");
        assert(words.size() >= 3 && "Error in map file!");
        float posx = strtof(words[1].c_str(), nullptr);
        float posy = strtof(words[2].c_str(), nullptr);
        sf::Vector2f block_position(posx, posy);
        sf::Vector2i block_offset;
        if      (words[0] == "dirt") block_offset = {576, 864};
        else if (words[0] == "grass") block_offset = {504, 576};
        else if (words[0] == "grassround") block_offset = {648, 0};
        m_blocks.push_back(std::make_shared<Block>(m_tiles, block_position, sf::Vector2i(70, 70), block_offset));
    }
    p.reset(new Player({700.f, 100.f}));
    m_entities.push_back(p);

    map.close();
}

void WorldLoader::reload(std::string filename) {
// TODO Reload method
    m_blocks.clear();
//    load(std::move(filename), ?);
}

