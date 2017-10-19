#include "World.hpp"

World::World(const Config& config) : WorldLoader(config), m_player(std::make_shared<Player>()) {
    load("../Resources/Maps/map1", m_player);
}

void World::update(float frametime) {
//    reload("../Resources/Maps/map2");
    m_player->update(frametime);
    detectCollision();
    m_player->move();
}

void World::render(const RenderManager& renderer) {
    for (std::shared_ptr<Entity> ent : m_entities) {
        renderer.drawEntity(*ent);
    }
    for (std::shared_ptr<Block> block : m_blocks) {
        renderer.drawBlock(*block);
    }
}

void World::detectCollision() {
    for (std::shared_ptr<Entity> ent : m_entities) {
        for (std::shared_ptr<Block> block : m_blocks) {
            COLLISION_TYPE col_type = ent->getCollider()
                    .detectCollision(block->bounding_box, ent->velocity);
            if(col_type != COLLISION_TYPE::NO_COLLISION) {
                ent->resolveCollision(col_type);
            }
        }
    }
}
