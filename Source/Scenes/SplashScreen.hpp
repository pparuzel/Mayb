#ifndef MAYBSFML_SPLASHSCREEN_HPP
#define MAYBSFML_SPLASHSCREEN_HPP

#include "Config.hpp"
#include "Scenes/Scene.hpp"
#include "Utils/FPSCounter.hpp"

class SplashScreen : public Scene
{
    std::vector<sf::Sprite> sprites_;
    std::vector<sf::Texture> textures_;
    FPSCounter fpsCounter_;
    float counter_;
    int trans_;
    int direction_;
    bool isRunning_;

public:
    explicit SplashScreen(sf::RenderWindow& window);

    SceneType nextScene() const override;

private:
    void doUpdate() override;
    void doRender(sf::RenderWindow& window) override;
    bool doHandleEvents(sf::RenderWindow& window) override;
    void showLogo();

    static constexpr float transitionDelay = .1f;
    static constexpr int precision = 255;
};

#endif  // MAYBSFML_SPLASHSCREEN_HPP
