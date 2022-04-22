#ifndef MAYBSFML_MENUSCENE_HPP
#define MAYBSFML_MENUSCENE_HPP

#include "Rendering/RenderManager.hpp"
#include "Scenes/Scene.hpp"
#include "Utils/FPSCounter.hpp"
#include "Utils/SpriteBuilder.hpp"

class MenuScene : public Scene
{
    FPSCounter fpsCounter_;
    SpriteBuilder buttons_;
    sf::Uint8 currentButton_;
    sf::Uint8 numberOfButtons_;

public:
    explicit MenuScene(sf::RenderWindow& window);
    SceneType nextScene() const override;

private:
    bool doHandleEvents(sf::RenderWindow& window) override;
    void doUpdate() override;
    void doRender(sf::RenderWindow& window) override;
};

#endif  // MAYBSFML_MENUSCENE_HPP
