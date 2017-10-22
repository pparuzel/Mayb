#include "Block.hpp"

Block::Block()
        : size{0, 0}, position{0.f, 0.f}, bounding_box(position, size), rect(), offset(0, 0) {
    tiles.loadFromFile("../Resources/tiles3.png");
}

sf::Texture Block::tiles{};
