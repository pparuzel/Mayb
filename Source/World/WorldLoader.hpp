#ifndef MAYBSFML_WORLDLOADER_HPP
#define MAYBSFML_WORLDLOADER_HPP

#include "Config.hpp"
#include "Entity.hpp"
#include "Objects/Block.hpp"
#include "Player/Player.hpp"
#include "Utils/ResourceManager.hpp"

#include <vector>

class WorldLoader
{

protected:
    std::vector<std::shared_ptr<Block>> blocks_;
    std::vector<std::shared_ptr<Entity>> entities_;

public:
    explicit WorldLoader();

    void load(const std_fs::path& filepath, std::shared_ptr<Player>&);
    void reload(const std_fs::path& filepath);
};

#endif  // MAYBSFML_WORLDLOADER_HPP
