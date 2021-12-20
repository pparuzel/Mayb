#ifndef MAYBSFML_SPLASHSCREEN_HPP
#define MAYBSFML_SPLASHSCREEN_HPP

#include "Config.hpp"
#include "Scenes/Scene.hpp"
#include "Utils/FPSCounter.hpp"

class SplashScreen : public Scene
{
    std::vector<sf::Sprite> sprites_;
    std::vector<sf::Texture> textures_;
    const FPSCounter& fpsCounter_;
    float counter_;
    int trans_;
    int direction_;

public:
    SplashScreen(const Config&, const FPSCounter& fpsCounter);

    void update() override;
    void render(const RenderManager& renderer) override;
    [[nodiscard]] std::string_view nextScene() const override;
    void handleEvents(sf::RenderWindow& window) override;

private:
    void showLogo();

    static constexpr float transitionDelay = .1f;
    static constexpr int precision = 255;
};

#endif  // MAYBSFML_SPLASHSCREEN_HPP
