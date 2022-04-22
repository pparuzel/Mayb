#include "Config.hpp"

#include <SFML/Graphics.hpp>

Config& getConfig()
{
    static Config config{};
    return config;
}

void Config::reconfigureWindow(sf::RenderWindow& window)
{
    window.setFramerateLimit(fpsCap);
    window.setVerticalSyncEnabled(isVSyncEnabled);
}
