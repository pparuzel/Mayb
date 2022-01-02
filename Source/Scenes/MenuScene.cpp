#include "MenuScene.hpp"

MenuScene::MenuScene(const Config& config, const FPSCounter& fpsCounter)
    : fpsCounter_(fpsCounter)
    , currentButton_(0)
    , numberOfButtons_(3)
{
    buttons_.build("MainMenu/menu_bg.png", {0.f, 0.f});
    buttons_.build("MainMenu/newgame_button.png", {360, 200});
    buttons_.build("MainMenu/load_button.png", {360, 320});
    buttons_.build("MainMenu/exit_button.png", {360, 440});
}

void MenuScene::render(const RenderManager& renderer)
{
    renderer.refresh(sf::Color{153, 204, 255});
    for (const auto& button : buttons_.sprites())
    {
        renderer.loadSprite(button);
    }
    sf::RectangleShape indicator({548, 96});
    indicator.setFillColor(sf::Color{255, 255, 255, 80});
    indicator.setPosition({360.f, 200.f + 120.f * static_cast<float>(currentButton_)});
    renderer.drawSFML(indicator);
}

void MenuScene::update()
{
}

#include <iostream>

void MenuScene::handleEvents(sf::RenderWindow& window)
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Enter:
                {
                    switch (currentButton_)
                    {
                        case 0: endScene(); break;
                        case 2: window.close(); break;
                        default: break;
                    }
                    break;
                }
                case sf::Keyboard::Up: [[fallthrough]];
                case sf::Keyboard::W:
                {
                    currentButton_ += numberOfButtons_ - 1;
                    currentButton_ %= numberOfButtons_;
                    break;
                }
                case sf::Keyboard::Down: [[fallthrough]];
                case sf::Keyboard::S:
                {
                    currentButton_ += 1;
                    currentButton_ %= numberOfButtons_;
                    break;
                }
                default: break;
            }
        }
    }
}

std::string_view MenuScene::nextScene() const
{
    return "GameScene";
}
