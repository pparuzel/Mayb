#ifndef MAYBSFML_FUNCTIONMANAGER_HPP
#define MAYBSFML_FUNCTIONMANAGER_HPP


#include <memory>
#include "IFunctionState.hpp"
#include "NoFunction.hpp"
#include "../../Utils/Stash.hpp"
#include "../Button.hpp"

class FunctionManager {
    std::unique_ptr<IFunctionState> m_currentState;
    std::vector<Button>             m_buttons;
    Stash                           m_stash;
public:
    FunctionManager() : m_currentState(std::make_unique<NoFunction>()) {
        setupTools();
    }

    void handleEvents(sf::RenderWindow& window) {
        sf::Event e{};
        while (window.pollEvent(e)) {
            if (e.type == e.Closed) { window.close(); }
        }
    }

    void render(const RenderManager& renderer) {
        for (const auto& elem : m_buttons) {
            renderer.loadSprite(elem);
        }
    }

    void setFunction(IFunctionState* functionState) {
        m_currentState.reset(functionState);
    }

    void setDefaultFunction() {
        m_currentState.reset(new NoFunction);
    }
private:
    void setupTools() {
        m_stash.add("dirt_lrrl", 0, 0);
        m_stash.add("dirt_llll", 0, 70);
        int i = 0;
        for (const auto& elem : m_stash.data()) {
            Button b(elem.first, m_stash.getSprite(elem.first));
            b.setPosition(240 + 90 * i, 20);
            m_buttons.push_back(std::move(b));
            // push b;
            ++i;
        }
    }
};


#endif //MAYBSFML_FUNCTIONMANAGER_HPP
