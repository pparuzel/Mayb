#include "World.hpp"

World::World(const Config& config) : WorldLoader(config) {
    load("../Resources/Maps/map1");
}

void World::generate() {
    reload("../Resources/Maps/map2");
}

void World::render(const RenderManager& renderer) {
    for (const Block& block : m_blocks) {
        renderer.drawBlock(block);
    }
}

void World::detectCollision() {
    for (Entity& ent : m_entities) {
        for (const Block& blk : m_blocks) {
            ent.bounding_box.detectCollision(blk);
        }
    }
}
