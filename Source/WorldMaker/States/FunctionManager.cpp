#include "WorldMaker/States/FunctionManager.hpp"
#include "WorldMaker/States/NoFunction.hpp"
#include "WorldMaker/States/PlacerFunction.hpp"
#include "WorldMaker/States/RemovalFunction.hpp"

#include <iostream>

FunctionManager::FunctionManager()
    : currentState_(std::make_unique<NoFunction>(*this))
{
    setupTools();
}

void FunctionManager::setupTools()
{
    stash_.add("grassround", 70, 210);
    stash_.add("grass", 0, 70);
    stash_.add("dirt", 0, 210);
    int i = 0;
    for (const auto& elem : stash_.data())
    {
        Button b(elem.first, stash_.getSprite(elem.first));
        b.setPosition({240.f + 90.f * i, 20.f});
        buttons_.push_back(std::move(b));
        ++i;
    }
}

void FunctionManager::handleEvents(sf::RenderWindow& window)
{
    sf::Event e{};
    while (window.pollEvent(e))
    {
        if (e.type == e.Closed)
        {
            window.close();
        }
        else if (e.type == e.MouseButtonPressed)
        {
            mousePressed(e.mouseButton);
        }
        else if (e.type == e.MouseMoved)
        {
            mouseMoved(e.mouseMove);
        }
        else if (e.type == e.KeyPressed)
        {
            if (e.key.code == sf::Keyboard::Num1 and stateID_ != 1)
            {
                selectFunction<NoFunction>();
                stateID_ = 1;
            }
            else if (e.key.code == sf::Keyboard::Num2 and stateID_ != 2)
            {
                selectFunction<PlacerFunction>();
                stateID_ = 2;
            }
            else if (e.key.code == sf::Keyboard::Num3 and stateID_ != 3)
            {
                selectFunction<RemovalFunction>();
                stateID_ = 3;
            }
            else if (e.key.code == sf::Keyboard::S and stateID_ == 1)
            {
                generate();
            }
        }
    }
}

void FunctionManager::render(const RenderManager& renderer)
{
    sf::Vertex points[] = {sf::Vertex(sf::Vector2f(0, 140)), sf::Vertex(sf::Vector2f(0, 910))};
    for (int i = 0; i < 40; i++)
    {
        points[0].position.x = i * 35;
        points[1].position.x = i * 35;
        renderer.drawSFML(points, 2, sf::Lines);
    }
    points[0].position = {0, 140};
    points[1].position = {1260, 140};
    for (int i = 4; i < 26; i++)
    {
        points[0].position.y = i * 35;
        points[1].position.y = i * 35;
        renderer.drawSFML(points, 2, sf::Lines);
    }
    for (const auto& item : buttons_)
    {
        renderer.loadSprite(item);
    }
    for (const auto& item : blocks_)
    {
        renderer.loadSprite(item);
    }
    currentState_->render(renderer);
}

void FunctionManager::mousePressed(sf::Event::MouseButtonEvent buttonInfo)
{
    currentState_->mousePressed(buttonInfo.x, buttonInfo.y);
}

void FunctionManager::mouseMoved(sf::Event::MouseMoveEvent buttonInfo)
{
    if (buttonInfo.y > 140)
    {
        currentState_->mouseMoved(buttonInfo.x, buttonInfo.y);
    }
}

std::vector<Button>::const_iterator FunctionManager::detectButton(int posx, int posy) const
{
    for (auto iter = buttons_.begin(); iter != buttons_.end(); iter++)
    {
        if (iter->getGlobalBounds().contains(posx, posy))
        {
            return iter;
        }
    }
    return buttons_.end();
}

std::vector<Button>::const_iterator FunctionManager::detectBlock(
    const sf::FloatRect& block) const
{
    for (auto iter = blocks_.begin(); iter != blocks_.end(); iter++)
    {
        if (iter->getGlobalBounds().intersects(block))
        {
            return iter;
        }
    }
    return blocks_.end();
}

void FunctionManager::addBlock(const Button& b)
{
    blocks_.push_back(b);
}

void FunctionManager::removeBlock(std::vector<Button>::const_iterator b)
{
    blocks_.erase(b);
}

std::vector<Button>::const_iterator FunctionManager::blocksEnd() const
{
    return blocks_.end();
}

std::vector<Button>::const_iterator FunctionManager::buttonsEnd() const
{
    return buttons_.end();
}

void FunctionManager::generate()
{
    std::cout << "Saving...\n";
    std::ofstream file(ResourceManager::getLocation() / "Maps" / "levelX1.map");
    for (auto& item : blocks_)
    {
        file << "[" << item.getID() << "] [" << item.getPosition().x << ", "
             << item.getPosition().y - 140 << "]\n";
    }
    file.close();
}
