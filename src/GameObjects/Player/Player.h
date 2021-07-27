//
// Created by Meevere on 5/30/2021.
//

#ifndef INFLAMMABLE_PLAYER_H
#define INFLAMMABLE_PLAYER_H

#include <iostream>
#include "GameObjects/PhysObject.h"

class Player: public PhysObject {
public:
    explicit Player();
    explicit Player(Vector2f _pos);

    void move(sf::Time elapsed) override;
};


#endif //INFLAMMABLE_PLAYER_H
