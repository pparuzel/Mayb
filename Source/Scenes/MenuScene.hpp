#ifndef MAYBSFML_MENUSCENE_HPP
#define MAYBSFML_MENUSCENE_HPP


#include "Scene.hpp"
#include "../Rendering/RenderManager.hpp"

class MenuScene : public Scene {
public:
    void generate() override;

    void render(const RenderManager& ) override;
};


#endif //MAYBSFML_MENUSCENE_HPP
