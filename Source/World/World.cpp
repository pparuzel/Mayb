#include "World.hpp"

World::World(const Config& config) : WorldLoader(config), m_player(std::make_shared<Player>()) {
    load("../Resources/Maps/level0.map", m_player);
}

void World::update(float frametime) {
    m_player->update(frametime);
    detectCollision();
    m_player->move();
}

void World::render(const RenderManager& renderer) {
    for (std::shared_ptr<Block> block : m_blocks) {
        renderer.drawBlock(*block);
    }
    for (std::shared_ptr<Entity> ent : m_entities) {
        renderer.drawEntity(*ent);
    }
}

void World::detectCollision() {
    COLLISION_TYPE collType;
    for (std::shared_ptr<Entity> ent : m_entities) {
        for (std::shared_ptr<Block> block : m_blocks) {
            collType =
                    ent->bounding_box.detectCollision(block->bounding_box, ent->velocity);
                ent->resolveCollision(collType);
        }
    }
}
