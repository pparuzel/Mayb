#ifndef MAYBSFML_BUTTON_HPP
#define MAYBSFML_BUTTON_HPP


#include <SFML/Graphics.hpp>

class Button : public sf::Sprite {
    std::string m_id;
public:
    explicit Button(std::string id, sf::Texture* texture, sf::IntRect rect)
            : m_id(std::move(id)), sf::Sprite(*texture, rect) {
    }

    explicit Button(std::string id, sf::Sprite sprite)
            : m_id(std::move(id)), sf::Sprite(std::move(sprite)) {}

    const std::string& getID() const {
        return m_id;
    }
};


#endif //MAYBSFML_BUTTON_HPP
