#ifndef MAYBSFML_MENUSCENE_HPP
#define MAYBSFML_MENUSCENE_HPP


#include "Scene.hpp"
#include "../Rendering/RenderManager.hpp"
#include "../Config.hpp"

class MenuScene : public Scene {
public:
    MenuScene(const Config& );

    void generate() override;

    void render(const RenderManager& ) override;
};


#endif //MAYBSFML_MENUSCENE_HPP
