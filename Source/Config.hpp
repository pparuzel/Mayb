#ifndef MAYBSFML_CONFIG_H
#define MAYBSFML_CONFIG_H

#include <SFML/Graphics.hpp>

struct Config
{
    unsigned int width = 1260;
    unsigned int height = 770;
    unsigned int fpsCap = 120;
    bool isVSyncEnabled = true;
    bool skipSplashScreen = false;

    void reconfigureWindow(sf::RenderWindow& window);
};

Config& getConfig();

#endif  // MAYBSFML_CONFIG_H
