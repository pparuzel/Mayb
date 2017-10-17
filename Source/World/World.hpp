#ifndef MAYBSFML_WORLD_HPP
#define MAYBSFML_WORLD_HPP


#include "../Rendering/RenderManager.hpp"
#include "WorldLoader.hpp"

class World : public WorldLoader {
public:
    World(const Config&);

    void generate();

    void render(const RenderManager& );
};


#endif //MAYBSFML_WORLD_HPP
