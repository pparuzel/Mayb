#ifndef MAYBSFML_WORLD_HPP
#define MAYBSFML_WORLD_HPP


#include "../Config.hpp"
#include "WorldLoader.hpp"
#include "../Rendering/RenderManager.hpp"
#include "../Player/Player.hpp"

class World : public WorldLoader {
    std::shared_ptr<Player> m_player;
public:
    World(const Config&);

    void update(float );

    void render(const RenderManager& );

    void detectCollision(float );
};


#endif //MAYBSFML_WORLD_HPP
