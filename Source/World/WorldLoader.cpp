#include "WorldLoader.hpp"

#include "TextureCache.hpp"

#include <cassert>
#include <iostream>

WorldLoader::WorldLoader(const Config& config)
    : config(config)
{
    TextureCache::getInstance().fetch("Tiles", std_fs::path("World") / "tileset.png");
}

std::vector<std::string> split(const std::string& str, const std::string& delimiter = " ")
{
    std::vector<std::string> words;
    std::string temp{};
    for (int i = 0; i <= str.length(); ++i)
    {
        bool hasDelimiter = false;
        for (int j = 0; j <= delimiter.length(); ++j)
        {
            if (str[i] == delimiter[j])
            {
                hasDelimiter = true;
                break;
            }
        }
        if (!hasDelimiter)
        {
            temp += str[i];
        }
        else if (!temp.empty())
        {
            words.push_back(temp);
            temp = "";
        }
    }
    return words;
}

void WorldLoader::load(const std_fs::path& filepath, std::shared_ptr<Player>& p)
{
    const auto* foundTilesTexture = TextureCache::getInstance().find("Tiles");
    if (!foundTilesTexture)
    {
        std::cerr << "error: Could not find 'Tiles' texture" << std::endl;
        std::terminate();
    }
    const auto mapFileLocation = ResourceManager::getLocation() / "Maps" / filepath;
    if (!std_fs::exists(mapFileLocation))
    {
        std::cerr << "error: Could not load " << mapFileLocation << std::endl;
        std::terminate();
    }
    auto mapFile = std::ifstream(mapFileLocation);
    std::string line;
    while (std::getline(mapFile, line))
    {
        auto words = split(line, "[ ],");
        assert(words.size() >= 3 && "Error in map file!");
        float posx = strtof(words[1].c_str(), nullptr);
        float posy = strtof(words[2].c_str(), nullptr);
        sf::Vector2f block_position(posx, posy);
        sf::Vector2i block_offset;
        if (words[0] == "dirt")
        {
            block_offset = {0, 210};
        }
        else if (words[0] == "grass")
        {
            block_offset = {0, 70};
        }
        else if (words[0] == "grassround")
        {
            block_offset = {70, 210};
        }
        blocks_.push_back(std::make_shared<Block>(
            *foundTilesTexture, block_position, sf::Vector2i(70, 70), block_offset));
    }
    p = std::make_shared<Player>(sf::Vector2f(700.f, 100.f));
    entities_.push_back(p);

    mapFile.close();
}

void WorldLoader::reload(const std_fs::path& filename)
{
    // TODO Reload method
    blocks_.clear();
    //    load(std::move(filename), ?);
}
