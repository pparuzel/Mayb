#include "MenuScene.hpp"

#include "Config.hpp"

MenuScene::MenuScene(sf::RenderWindow& window)
    : fpsCounter_()
    , currentButton_(0)
    , numberOfButtons_(3)
{
    auto& config = getConfig();
    config.fpsCap = 0;
    config.isVSyncEnabled = false;
    config.reconfigureWindow(window);
    buttons_.build("MainMenu/menu_bg.png", {0.f, 0.f});
    buttons_.build("MainMenu/newgame_button.png", {360, 200});
    buttons_.build("MainMenu/load_button.png", {360, 320});
    buttons_.build("MainMenu/exit_button.png", {360, 440});
}

void MenuScene::doRender(sf::RenderWindow& window)
{
    // window.clear();  // FIXME: Clears the seconds time here...
    // sf::Color{153, 204, 255}
    // window.clear(sf::Color::Yellow);
    for (const auto& button : buttons_.sprites())
    {
        window.draw(button);
    }
    sf::RectangleShape indicator({548, 96});
    indicator.setFillColor(sf::Color{255, 255, 255, 80});
    indicator.setPosition({360.f, 200.f + 120.f * static_cast<float>(currentButton_)});
    window.draw(indicator);
    fpsCounter_.draw(window);
}

void MenuScene::doUpdate()
{
    fpsCounter_.update();
}

bool MenuScene::doHandleEvents(sf::RenderWindow& window)
{
    bool isRunning = true;
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
                        case 0:
                            isRunning = false;
                            break;  // can it return here or does it have to poll all events?
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
    return isRunning;
}

SceneType MenuScene::nextScene() const
{
    return SceneType::GameScene;
}
