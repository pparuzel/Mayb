#ifndef MAYBSFML_MENUSCENE_HPP
#define MAYBSFML_MENUSCENE_HPP


#include "../Rendering/RenderManager.hpp"
#include "../Config.hpp"
#include "Scene.hpp"

class MenuScene : public Scene {
public:
    explicit MenuScene(const Config& );

    void update() override;

    void render(const RenderManager& ) override;
};


#endif //MAYBSFML_MENUSCENE_HPP
