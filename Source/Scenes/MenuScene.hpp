#ifndef MAYBSFML_MENUSCENE_HPP
#define MAYBSFML_MENUSCENE_HPP


#include <array>
#include "../Rendering/RenderManager.hpp"
#include "../Utils/FPSCounter.hpp"
#include "../Config.hpp"
#include "Scene.hpp"
#include "../Utils/SpriteBuilder.hpp"

class MenuScene : public Scene {
    const FPSCounter&   m_fpsCounter;
    SpriteBuilder       m_buttons;
    int                 m_currentButton;
public:
    explicit MenuScene(const Config& config, const FPSCounter& fpsCounter);

    void update() override;

    void render(const RenderManager&) override;

    const std::string nextScene() const override;
};


#endif //MAYBSFML_MENUSCENE_HPP
