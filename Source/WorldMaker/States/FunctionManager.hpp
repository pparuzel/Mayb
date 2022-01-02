#ifndef MAYBSFML_FUNCTIONMANAGER_HPP
#define MAYBSFML_FUNCTIONMANAGER_HPP

#include "../../Utils/Stash.hpp"
#include "../Button.hpp"
#include "IFunctionState.hpp"
#include <memory>

class FunctionManager
{
    std::unique_ptr<IFunctionState> currentState_;
    std::vector<Button> buttons_;
    std::vector<Button> blocks_;
    Stash stash_;
    int stateID_{1};

public:
    FunctionManager();

    void handleEvents(sf::RenderWindow& window);

    void render(const RenderManager& renderer);

    void addBlock(const Button& b);

    void removeBlock(std::vector<Button, std::__1::allocator<Button>>::const_iterator b);

    [[nodiscard]] std::vector<Button>::const_iterator detectButton(int posx, int posy) const;

    [[nodiscard]] std::vector<Button>::const_iterator detectBlock(const sf::FloatRect&) const;

    [[nodiscard]] std::vector<Button>::const_iterator blocksEnd() const;

    [[nodiscard]] std::vector<Button>::const_iterator buttonsEnd() const;

    template <typename T>
    void selectFunction()
    {
        currentState_ = std::make_unique<T>(*this);
    }

private:
    void mousePressed(sf::Event::MouseButtonEvent buttonInfo);

    void mouseMoved(sf::Event::MouseMoveEvent buttonInfo);

    void setupTools();

    void generate();
};

#endif  // MAYBSFML_FUNCTIONMANAGER_HPP
