//
// Created by Meevere on 7/27/2021.
//

#ifndef INFLAMMABLE_WALL_H
#define INFLAMMABLE_WALL_H

#include "GameObjects/PhysObject.h"

class Wall: public PhysObject{
public:
    Wall(Vector2f pos, Vector2f size_);

    void move(sf::Time elapsed) override;
};


#endif //INFLAMMABLE_WALL_H
