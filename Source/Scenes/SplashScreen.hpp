#ifndef MAYBSFML_SPLASHSCREEN_HPP
#define MAYBSFML_SPLASHSCREEN_HPP


#include <iostream>
#include "../Utils/FPSCounter.hpp"
#include "../Config.hpp"
#include "Scene.hpp"


class SplashScreen : public Scene {
    std::vector<sf::Sprite>     m_sprites;
    std::vector<sf::Texture>    m_textures;
    const FPSCounter&           m_fpsCounter;
    float                       m_counter;
    int                         m_trans;
    int                         m_direction;
public:
    SplashScreen(const Config&, const FPSCounter& fpsCounter);

    void update() override;

    void render(const RenderManager& renderer) override;
private:
    void showLogo();

    static constexpr float transitionDelay = .1f;
    static constexpr int   precision       = 255;
};


#endif //MAYBSFML_SPLASHSCREEN_HPP
