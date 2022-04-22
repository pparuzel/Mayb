#include "Scene.hpp"

bool Scene::updateAndRender(sf::RenderWindow& window)
{
    const bool doContinue = doHandleEvents(window);
    doUpdate();
    window.clear(backgroundColor_);
    doRender(window);
    window.display();
    return doContinue;
}

void Scene::setBackgroundColor(sf::Color color)
{
    backgroundColor_ = color;
}

sf::Color Scene::getBackgroundColor() const
{
    return backgroundColor_;
}
