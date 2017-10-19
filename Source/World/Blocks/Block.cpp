#include <iostream>
#include "Block.hpp"

Block::Block()
        : size{100.f, 100.f}, position{0.f, 0.f}, bounding_box(position, size) {}
