#ifndef MAYBSFML_WORLD_HPP
#define MAYBSFML_WORLD_HPP


#include "../Rendering/RenderManager.hpp"
#include "WorldMap.hpp"

class World {
    WorldMap m_map;
public:
    World(const Config&);

    void generate(std::string );

    void render(const RenderManager& );
};


#endif //MAYBSFML_WORLD_HPP
