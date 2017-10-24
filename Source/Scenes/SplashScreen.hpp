#ifndef MAYBSFML_SPLASHSCREEN_HPP
#define MAYBSFML_SPLASHSCREEN_HPP


#include <iostream>
#include "../Utils/FPSCounter.hpp"
#include "../Config.hpp"
#include "Scene.hpp"


class SplashScreen : public Scene {
    const FPSCounter&   m_fpsCounter;
    sf::Sprite          m_splash;
    sf::Texture         m_texture;
    float               m_counter;
    int                 m_trans;
public:
    SplashScreen(const Config&, const FPSCounter& fpsCounter);

    void update() override;

    void render(const RenderManager& renderer) override;
private:
    static constexpr float transitionDelay = .2f;
    static constexpr int   precision       = 300;
};


#endif //MAYBSFML_SPLASHSCREEN_HPP
