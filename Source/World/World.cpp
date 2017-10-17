#include "World.hpp"

World::World(const Config& config) : m_map(config) {
    m_map.load("../Resources/Maps/map1");
}

void World::generate(std::string filename) {
    m_map.reload(filename);
}

void World::render(const RenderManager& renderer) {
    for (const Block& block : m_map.blocks()) {
        renderer.drawBlock(block);
    }
}
