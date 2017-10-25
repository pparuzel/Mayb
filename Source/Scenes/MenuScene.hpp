#ifndef MAYBSFML_MENUSCENE_HPP
#define MAYBSFML_MENUSCENE_HPP


#include <array>
#include "../Rendering/RenderManager.hpp"
#include "../Utils/FPSCounter.hpp"
#include "../Config.hpp"
#include "Scene.hpp"

class MenuScene : public Scene {
    std::vector<sf::Texture>    m_textures;
    const FPSCounter&           m_fpsCounter;
    std::array<bool, 1>         m_focusedButton;
public:
    explicit MenuScene(const Config& config, const FPSCounter& fpsCounter);

    void update() override;

    void render(const RenderManager&) override;

    const std::string nextScene() const override;
};


#endif //MAYBSFML_MENUSCENE_HPP
