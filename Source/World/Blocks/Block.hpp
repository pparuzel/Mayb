#ifndef MAYBSFML_BLOCK_HPP
#define MAYBSFML_BLOCK_HPP


#include "../../Maths/Vector2.hpp"
#include "../../Maths/Collider.hpp"


struct Block {
    static sf::Texture tiles;
    sf::IntRect rect;
    sf::Vector2i offset;
    Vector2 position;
    Vector2 size;
    Collider bounding_box;

    Block();
};


#endif //MAYBSFML_BLOCK_HPP
