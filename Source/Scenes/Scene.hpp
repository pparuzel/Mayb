#ifndef MAYBSFML_SCENE_HPP
#define MAYBSFML_SCENE_HPP


#include "../Rendering/RenderManager.hpp"

struct Scene {
    virtual void update() = 0;
    virtual void render(const RenderManager&) = 0;
};


#endif //MAYBSFML_SCENE_HPP
