#ifndef MAYBSFML_SCENE_HPP
#define MAYBSFML_SCENE_HPP


#include "../Rendering/RenderManager.hpp"

class Scene {
protected:
    bool hasFinished = false;
public:
    bool closed() { return hasFinished; }
    virtual const std::string nextScene() const = 0;
    virtual void update() = 0;
    virtual void render(const RenderManager&) = 0;

    virtual ~Scene() = default;
};


#endif //MAYBSFML_SCENE_HPP
