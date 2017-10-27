#ifndef MAYBSFML_MENUSCENE_HPP
#define MAYBSFML_MENUSCENE_HPP


#include <array>
#include "../Rendering/RenderManager.hpp"
#include "../Utils/SpriteBuilder.hpp"
#include "../Utils/FPSCounter.hpp"
#include "../Config.hpp"
#include "Scene.hpp"

class MenuScene : public Scene {
    const FPSCounter&   m_fpsCounter;
    SpriteBuilder       m_buttons;
    int                 m_currentButton;
    int                 m_numberOfButtons;
    bool                m_locked;
public:
    explicit MenuScene(const Config&, const FPSCounter&);

    void update() override;

    void render(const RenderManager&) override;

    const std::string nextScene() const override;

    // TODO handle events
    void handleEvents(sf::RenderWindow& window) override;
};


#endif //MAYBSFML_MENUSCENE_HPP
