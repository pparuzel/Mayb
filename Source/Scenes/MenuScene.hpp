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
    sf::RenderWindow*   m_window;
    int                 m_currentButton;
    int                 m_numberOfButtons;
    bool                m_locked;
public:
    explicit MenuScene(const Config&, const FPSCounter&, sf::RenderWindow*);

    void update() override;

    void render(const RenderManager&) override;

    const std::string nextScene() const override;

    // TODO handle events
    void handleEvents(sf::RenderWindow& window) override;
};


#endif //MAYBSFML_MENUSCENE_HPP
