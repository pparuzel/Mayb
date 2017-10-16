#ifndef MAYBSFML_WORLD_HPP
#define MAYBSFML_WORLD_HPP


#include "../Rendering/RenderManager.hpp"
#include "WorldMap.hpp"

class World {
public:
    World();

    void generate(WorldMap);

    void render(RenderManager& );
};


#endif //MAYBSFML_WORLD_HPP
