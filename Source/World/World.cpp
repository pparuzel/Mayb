#include "World.hpp"

World::World()
    : WorldLoader()
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

void World::render(sf::RenderWindow& window)
{
    window.clear(sf::Color{153, 204, 255});
    for (const std::shared_ptr<Block>& block : blocks_)
    {
        window.draw(block->sprite());
    }
    for (const std::shared_ptr<Entity>& ent : entities_)
    {
        window.draw(ent->sprite());
    }
}

void World::handleCollision()
{
    for (std::shared_ptr<Entity>& ent : entities_)
    {
        for (const std::shared_ptr<Block>& block : blocks_)
        {
            CollisionType collType = ent->AABBox().detectRectCollision(block->AABBox(), ent->velocity());
            ent->resolveCollision(collType);
        }
    }
}

bool World::isGameOver() const
{
    return isGameOver_;
}
