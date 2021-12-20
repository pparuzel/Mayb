#ifndef MAYBSFML_MENUSCENE_HPP
#define MAYBSFML_MENUSCENE_HPP

#include "Config.hpp"
#include "Rendering/RenderManager.hpp"
#include "Scenes/Scene.hpp"
#include "Utils/FPSCounter.hpp"
#include "Utils/SpriteBuilder.hpp"

#include <array>

class MenuScene : public Scene
{
    const FPSCounter& fpsCounter_;
    SpriteBuilder buttons_;
    sf::Uint8 currentButton_;
    sf::Uint8 numberOfButtons_;

public:
    explicit MenuScene(const Config&, const FPSCounter&);

    void update() override;
    void render(const RenderManager& renderer) override;
    [[nodiscard]] std::string_view nextScene() const override;
    void handleEvents(sf::RenderWindow& window) override;
};

#endif  // MAYBSFML_MENUSCENE_HPP
