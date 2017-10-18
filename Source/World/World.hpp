#ifndef MAYBSFML_WORLD_HPP
#define MAYBSFML_WORLD_HPP


#include "../Config.hpp"
#include "WorldLoader.hpp"
#include "../Rendering/RenderManager.hpp"

class World : public WorldLoader {
public:
    World(const Config&);

    void generate();

    void render(const RenderManager& );

    void detectCollision();
};


#endif //MAYBSFML_WORLD_HPP
