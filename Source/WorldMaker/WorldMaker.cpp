#include "WorldMaker.hpp"

WorldMaker::WorldMaker(const Config& config)
    : window_()
    , renderer_(window_)
    , functionManager_()
{
    window_.create(sf::VideoMode(config.width, config.height + 140), "Mayb2D World Maker");
    window_.setFramerateLimit(config.fps_cap);
    window_.setVerticalSyncEnabled(config.isVSyncOn);
}

void WorldMaker::run()
{
    while (window_.isOpen())
    {
        window_.clear(sf::Color{153, 204, 255});
        functionManager_.handleEvents(window_);
        functionManager_.render(renderer_);
        window_.display();
    }
}
