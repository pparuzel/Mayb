#ifndef MAYBSFML_FUNCTIONMANAGER_HPP
#define MAYBSFML_FUNCTIONMANAGER_HPP


#include <memory>
#include "IFunctionState.hpp"
#include "../../Utils/Stash.hpp"
#include "../Button.hpp"

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

    void addBlock(const sf::Sprite& b);

    void removeBlock(std::vector<sf::Sprite, std::__1::allocator<sf::Sprite>>::const_iterator b);

    const sf::Sprite* detectButton(int posx, int posy) const;

    std::vector<sf::Sprite>::const_iterator detectBlock(const sf::FloatRect&) const;

    std::vector<sf::Sprite>::const_iterator blocksEnd() const;

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
