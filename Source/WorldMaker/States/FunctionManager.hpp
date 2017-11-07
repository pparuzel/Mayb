#ifndef MAYBSFML_FUNCTIONMANAGER_HPP
#define MAYBSFML_FUNCTIONMANAGER_HPP


#include <memory>
#include "IFunctionState.hpp"
#include "NoFunction.hpp"
#include "../../Utils/Stash.hpp"
#include "../Button.hpp"
#include "PlacerFunction.hpp"

class FunctionManager {
    std::unique_ptr<IFunctionState> m_currentState;
    std::vector<Button>             m_buttons;
    std::vector<sf::Sprite>         m_blocks;
    Stash                           m_stash;
    int                             m_stateID{1};
public:
    FunctionManager();

    void handleEvents(sf::RenderWindow& window);

    void render(const RenderManager& renderer);

    // TODO ZMIENIC BUTTON NA BLOCK
    void addBlock(const sf::Sprite& b) {
        m_blocks.push_back(b);
    }

    const std::vector<Button>& buttons() const;

    template<typename T>
    void selectFunction() {
        m_currentState.reset(new T(*this));
    }
private:
    void mousePressed(sf::Event::MouseButtonEvent buttonInfo);

    void mouseMoved(sf::Event::MouseMoveEvent buttonInfo);

    void setupTools();
};


#endif //MAYBSFML_FUNCTIONMANAGER_HPP
