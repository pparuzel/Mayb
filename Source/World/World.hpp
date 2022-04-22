#ifndef MAYBSFML_WORLD_HPP
#define MAYBSFML_WORLD_HPP

#include "../Config.hpp"
#include "../Player/Player.hpp"
#include "../Rendering/RenderManager.hpp"
#include "Objects/Block.hpp"
#include "WorldLoader.hpp"

class World : public WorldLoader
{
    std::shared_ptr<Player> player_;
    bool isGameOver_;

public:
    explicit World();
    void update(float);
    void render(sf::RenderWindow& window);
    void handleCollision();
    bool isGameOver() const;
};

#endif  // MAYBSFML_WORLD_HPP
