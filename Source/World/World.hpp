#ifndef MAYBSFML_WORLD_HPP
#define MAYBSFML_WORLD_HPP

#include "../Config.hpp"
#include "../Player/Player.hpp"
#include "../Rendering/RenderManager.hpp"
#include "Objects/Block.hpp"
#include "WorldLoader.hpp"

class World : public WorldLoader
{
    std::shared_ptr<Player> player_;
    bool isGameOver_;

public:
    explicit World(const Config&);

    void update(float);

    void render(const RenderManager&);

    void handleCollision();

    bool isGameOver();
};

#endif  // MAYBSFML_WORLD_HPP
