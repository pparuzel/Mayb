#ifndef MAYBSFML_SCENE_HPP
#define MAYBSFML_SCENE_HPP

#include "../Rendering/RenderManager.hpp"

class Scene
{
public:
    Scene() = default;
    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;
    Scene(Scene&&) = default;
    Scene& operator=(Scene&&) = delete;
    virtual ~Scene() = default;

    [[nodiscard]] bool closed() const { return hasFinished; }
    [[nodiscard]] virtual std::string_view nextScene() const = 0;
    virtual void update() = 0;
    virtual void render(const RenderManager&) = 0;
    virtual void handleEvents(sf::RenderWindow&) = 0;

    void endScene() { hasFinished = true; }
    void restartScene() { hasFinished = false; }
    [[nodiscard]] bool sceneRunning() const { return hasFinished; }

private:
    bool hasFinished = false;
};

#endif  // MAYBSFML_SCENE_HPP
