#include "FunctionManager.hpp"
#include "RemovalFunction.hpp"
#include "NoFunction.hpp"
#include "PlacerFunction.hpp"

FunctionManager::FunctionManager() : m_currentState(std::make_unique<NoFunction>(*this)) {
    setupTools();
}

void FunctionManager::setupTools() {
    m_stash.add("grassround", 70, 210);
    m_stash.add("grass", 0, 70);
    m_stash.add("dirt", 0, 210);
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
            } else if (e.key.code == sf::Keyboard::S and m_stateID == 1) {
                generate();
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
    for (const auto& item : m_blocks) {
        renderer.loadSprite(item);
    }
    m_currentState->render(renderer);
}

void FunctionManager::mousePressed(sf::Event::MouseButtonEvent buttonInfo) {
    m_currentState->mousePressed(buttonInfo.x, buttonInfo.y);
}

void FunctionManager::mouseMoved(sf::Event::MouseMoveEvent buttonInfo) {
    if (buttonInfo.y > 140) {
        m_currentState->mouseMoved(buttonInfo.x, buttonInfo.y);
    }
}

std::vector<Button>::const_iterator FunctionManager::detectButton(int posx, int posy) const {
    for (auto iter = m_buttons.begin(); iter != m_buttons.end(); iter++) {
        if (iter->getGlobalBounds().contains(posx, posy)) {
            return iter;
        }
    }
    return m_buttons.end();
}

std::vector<Button>::const_iterator FunctionManager::detectBlock(const sf::FloatRect& block) const {
    for (auto iter = m_blocks.begin(); iter != m_blocks.end(); iter++) {
        if (iter->getGlobalBounds().intersects(block)) {
            return iter;
        }
    }
    return m_blocks.end();
}

void FunctionManager::addBlock(const Button& b) {
    m_blocks.push_back(b);
}

void FunctionManager::removeBlock(std::vector<Button>::const_iterator b) {
    m_blocks.erase(b);
}

std::vector<Button>::const_iterator FunctionManager::blocksEnd() const {
    return m_blocks.end();
}

std::vector<Button>::const_iterator FunctionManager::buttonsEnd() const {
    return m_buttons.end();
}

void FunctionManager::generate() {
    printf("Saving...\n");
    std::ofstream file("../Resources/Maps/levelX1.map");
    for (auto& item : m_blocks) {
        file << "[" << item.getID() << "] [" << item.getPosition().x << ", " << item.getPosition().y-140 << "]\n";
    }
    file.close();
}
