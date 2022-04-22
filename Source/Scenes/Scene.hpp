#ifndef MAYBSFML_SCENE_HPP
#define MAYBSFML_SCENE_HPP

#include <SFML/Graphics.hpp>

enum class SceneType
{
    SplashScreen,
    MenuScene,
    GameScene,
};

class Scene
{
public:
    bool updateAndRender(sf::RenderWindow& window);
    void setBackgroundColor(sf::Color color);
    sf::Color getBackgroundColor() const;

    virtual SceneType nextScene() const = 0;
    virtual ~Scene() = default;

private:
    virtual void doUpdate() = 0;
    virtual void doRender(sf::RenderWindow&) = 0;
    virtual bool doHandleEvents(sf::RenderWindow&) = 0;

    sf::Color backgroundColor_{sf::Color::Black};
};

#endif  // MAYBSFML_SCENE_HPP
