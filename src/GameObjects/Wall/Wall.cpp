//
// Created by Meevere on 7/27/2021.
//

#include "Wall.h"

Wall::Wall(Vector2f pos, Vector2f size_) {
    position = pos;
    size = size_;
}

void Wall::move(sf::Time elapsed) {}