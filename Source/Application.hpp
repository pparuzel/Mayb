#ifndef MAYBSFML_APPLICATION_H
#define MAYBSFML_APPLICATION_H

#include "Scenes/Scene.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

class Application
{
public:
    explicit Application();
    void run();
    void changeScene(SceneType type);

private:
    sf::RenderWindow window_;
    std::unique_ptr<Scene> scene_;
};

#endif  // MAYBSFML_APPLICATION_H
