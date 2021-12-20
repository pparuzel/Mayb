#include "World.hpp"

World::World(const Config& config)
    : WorldLoader(config)
    , player_(nullptr)
    , isGameOver_(false)
{
    load("levelX1.map", player_);
}

void World::update(float frametime)
{
    player_->update(frametime);
    handleCollision();
    player_->move();
    if (player_->sprite().getPosition().y > 1000)
    {
        isGameOver_ = true;
    }
}

void World::render(const RenderManager& renderer)
{
    renderer.refresh(sf::Color{153, 204, 255});
    for (const std::shared_ptr<Block>& block : blocks_)
    {
        renderer.drawBlock(*block);
    }
    for (const std::shared_ptr<Entity>& ent : entities_)
    {
        renderer.drawEntity(*ent);
    }
}

void World::handleCollision()
{
    CollisionType collType;
    for (std::shared_ptr<Entity>& ent : entities_)
    {
        for (const std::shared_ptr<Block>& block : blocks_)
        {
            collType = ent->AABBox().detectRectCollision(block->AABBox(), ent->velocity());
            ent->resolveCollision(collType);
        }
    }
}

bool World::isGameOver()
{
    return isGameOver_;
}
