#ifndef MAYBSFML_BUTTON_HPP
#define MAYBSFML_BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button : public sf::Sprite
{
    std::string id_;

public:
    explicit Button(std::string id, sf::Texture* texture, sf::IntRect rect)
        : id_(std::move(id))
        , sf::Sprite(*texture, rect)
    {
    }

    explicit Button(std::string id, sf::Sprite sprite)
        : id_(std::move(id))
        , sf::Sprite(std::move(sprite))
    {
    }

    const std::string& getID() const { return id_; }
};

#endif  // MAYBSFML_BUTTON_HPP
