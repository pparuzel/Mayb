#ifndef BOOTLOADSCENE_HPP
#define BOOTLOADSCENE_HPP

#include "Scenes/Scene.hpp"

class Bootload : public Scene
{
public:
    explicit Bootload(sf::RenderWindow& window);
    SceneType nextScene() const override;

private:
    bool doHandleEvents(sf::RenderWindow& window) override { return false; }
    void doUpdate() override {}
    void doRender(sf::RenderWindow& window) override {}
};

#endif  // BOOTLOADSCENE_HPP
