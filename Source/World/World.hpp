#ifndef MAYBSFML_WORLD_HPP
#define MAYBSFML_WORLD_HPP


#include "Objects/Block.hpp"
#include "WorldLoader.hpp"
#include "../Rendering/RenderManager.hpp"
#include "../Player/Player.hpp"
#include "../Config.hpp"

class World : public WorldLoader {
    std::shared_ptr<Player> m_player;
    bool                    m_isGameOver;

public:
    explicit World(const Config&);

    void update(float);

    void render(const RenderManager&);

    void handleCollision();

    bool isGameOver();
};


#endif //MAYBSFML_WORLD_HPP
