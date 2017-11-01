#ifndef MAYBSFML_BUTTON_HPP
#define MAYBSFML_BUTTON_HPP


#include <SFML/Graphics.hpp>
#include <utility>
#include "../Utils/Stash.hpp"

class Button : public sf::Sprite {
    std::string m_id;
public:
    explicit Button(const Stash& stash, std::string id)
            : sf::Sprite(stash.getSprite(id)), m_id(std::move(id)) {
    }

    const std::string& getID() const {
        return m_id;
    }
};


#endif //MAYBSFML_BUTTON_HPP
