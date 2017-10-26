#include "World.hpp"

World::World(const Config& config)
        : WorldLoader(config), m_player(nullptr), m_isGameOver(false) {
    load("level0.map", m_player);
}

void World::update(float frametime) {
    m_player->update(frametime);
    handleCollision();
    m_player->move();
    if (m_player->sprite().getPosition().y > 1000) {
        m_isGameOver = true;
    }
}

void World::render(const RenderManager& renderer) {
    renderer.refresh(sf::Color{153, 204, 255});
    for (const std::shared_ptr<Block>& block : m_blocks) {
        renderer.drawBlock(*block);
    }
    for (const std::shared_ptr<Entity>& ent : m_entities) {
        renderer.drawEntity(*ent);
    }
}

void World::handleCollision() {
    CollisionType collType;
    for (std::shared_ptr<Entity>& ent : m_entities) {
        for (const std::shared_ptr<Block>& block : m_blocks) {
            collType = ent->AABBox().detectCollision(block->AABBox(), ent->velocity());
                ent->resolveCollision(collType);
        }
    }
}

bool World::isGameOver() {
    return m_isGameOver;
}
