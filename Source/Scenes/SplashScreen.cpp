#include "SplashScreen.hpp"

#include "Utils/ResourceManager.hpp"

#include <array>
#include <iostream>
#include <string_view>
#include <tuple>

using namespace std::string_view_literals;

SplashScreen::SplashScreen(const Config& config, const FPSCounter& fpsCounter)
    : fpsCounter_(fpsCounter)
    , counter_(0)
    , trans_(0)
    , direction_(1)
{
    constexpr static auto loadTexture = [](std::string_view resourceName)
    {
        std_fs::path path = ResourceManager::getLocation() / "SplashScreen" / resourceName;
        sf::Texture texture;
        if (!std_fs::exists(path) || !texture.loadFromFile(path))
        {
            std::cerr << "Could not load Splashscreen from path " << path << std::endl;
        }
        return texture;
    };
    static const auto SplashScreenResourceInfo = std::array{
        std::make_pair("splashscreen.png"sv, sf::Vector2f(400.f, 300.f)),
        std::make_pair("splashscreen2.png"sv, sf::Vector2f(1000.f, 700.f)),
        std::make_pair("xd.png"sv, sf::Vector2f(150.f, 150.f)),
    };
    textures_.reserve(SplashScreenResourceInfo.size());
    sprites_.reserve(SplashScreenResourceInfo.size());
    for (auto&& [resourceName, position] : SplashScreenResourceInfo)
    {
        const auto texture = loadTexture(resourceName);
        sprites_.emplace_back(textures_.emplace_back(texture)).setPosition(position);
    }
}

void SplashScreen::update()
{
    showLogo();
    if ((trans_ < 5 and direction_ == -1))
    {
        endScene();
    }
}

void SplashScreen::render(const RenderManager& renderer)
{
    sf::Uint8 alpha = 0;
    if (trans_ > 150)
        alpha = static_cast<sf::Uint8>(trans_ * 255.f / precision - 150);
    sprites_[0].setColor(
        sf::Color(255, 255, 255, static_cast<sf::Uint8>(trans_ * 255.f / precision)));
    sprites_[1].setColor(sf::Color(255, 255, 255, alpha));
    sprites_[2].setColor(sf::Color(255, 255, 255, 0));
    if (direction_ == -1)
    {
        sprites_[2].setColor(sf::Color(255, 255, 255, alpha));
    }
    for (const auto& sprite : sprites_)
    {
        renderer.loadSprite(sprite);
    }
}

void SplashScreen::showLogo()
{
    counter_ += fpsCounter_.frametime();
    if (counter_ < 1.5f)
    {
        return;
    }
    if (counter_ > transitionDelay)
    {
        if (trans_ == precision)
        {
            direction_ *= -1;
        }
        counter_ = 1.5f;
        trans_ += direction_;
    }
}

std::string_view SplashScreen::nextScene() const
{
    return "MenuScene";
}

void SplashScreen::handleEvents(sf::RenderWindow& window)
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == event.KeyPressed)
        {
            endScene();
        }
    }
}
