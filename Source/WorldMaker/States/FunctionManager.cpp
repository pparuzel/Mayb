#include "FunctionManager.hpp"

#include "RemovalFunction.hpp"
#include "NoFunction.hpp"
#include "PlacerFunction.hpp"

FunctionManager::FunctionManager() : m_currentState(std::make_unique<NoFunction>(*this)) {
    setupTools();
}

void FunctionManager::setupTools() {
    m_stash.add("dirt_lrrl", 0, 0);
    m_stash.add("dirt_llll", 0, 70);
    int i = 0;
    for (const auto& elem : m_stash.data()) {
        Button b(elem.first, m_stash.getSprite(elem.first));
        b.setPosition(240 + 90 * i, 20);
        m_buttons.push_back(std::move(b));
        ++i;
    }
}

void FunctionManager::handleEvents(sf::RenderWindow& window) {
    sf::Event e{};
    while (window.pollEvent(e)) {
        if (e.type == e.Closed)                  { window.close(); }
        else if (e.type == e.MouseButtonPressed) { mousePressed(e.mouseButton); }
        else if (e.type == e.MouseMoved)         { mouseMoved(e.mouseMove); }
        else if (e.type == e.KeyPressed) {
            if (e.key.code == sf::Keyboard::Num1 and m_stateID != 1) {
                selectFunction<NoFunction>();
                m_stateID = 1;
            } else if (e.key.code == sf::Keyboard::Num2 and m_stateID != 2) {
                selectFunction<PlacerFunction>();
                m_stateID = 2;
            } else if (e.key.code == sf::Keyboard::Num3 and m_stateID != 3) {
                selectFunction<RemovalFunction>();
                m_stateID = 3;
            }
        }
    }
}

void FunctionManager::render(const RenderManager& renderer) {
    sf::Vertex points[] = { sf::Vertex(sf::Vector2f(0, 140)), sf::Vertex(sf::Vector2f(0, 910)) };
    for (int i=0; i<40; i++) {
        points[0].position.x = i*35;
        points[1].position.x = i*35;
        renderer.drawSFML(points, 2, sf::Lines);
    }
    points[0].position = {0, 140};
    points[1].position = {1260, 140};
    for (int i=4; i<26; i++) {
        points[0].position.y = i*35;
        points[1].position.y = i*35;
        renderer.drawSFML(points, 2, sf::Lines);
    }
    for (const auto& item : m_buttons) {
        renderer.loadSprite(item);
    }
    m_currentState->render(renderer);
    for (const auto& item : m_blocks) {
        renderer.loadSprite(item);
    }
}

void FunctionManager::mousePressed(sf::Event::MouseButtonEvent buttonInfo) {
    m_currentState->mousePressed(buttonInfo.x, buttonInfo.y);
}

void FunctionManager::mouseMoved(sf::Event::MouseMoveEvent buttonInfo) {
    if (buttonInfo.y > 140) {
        m_currentState->mouseMoved(buttonInfo.x, buttonInfo.y);
    }
}

const sf::Sprite* FunctionManager::detectButton(int posx, int posy) const {
    for (const sf::Sprite& item : m_buttons) {
        if (item.getGlobalBounds().contains(posx, posy)) {
            return &item;
        }
    }
    return nullptr;
}

const sf::Sprite* FunctionManager::detectBlock(const sf::FloatRect& block) const {

    for (const sf::Sprite& item : m_blocks) {
        if (item.getGlobalBounds().intersects(block)) {
            return &item;
        }
    }
    return nullptr;
}

void FunctionManager::addBlock(const sf::Sprite& b) {
    m_blocks.push_back(b);
}
