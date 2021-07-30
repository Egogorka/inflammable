//
// Created by Meevere on 7/21/2021.
//

#ifndef INFLAMMABLE_PHYSOBJECT_H
#define INFLAMMABLE_PHYSOBJECT_H

#include "GameObject.h"

class PhysObject: public GameObject {
public:
    Vector2f velocity = Vector2f(0,0);
    Vector2f acceleration = Vector2f(0,0);
    // if 0 - no friction, better be positive for defined behaviour
    float friction = 0;
    virtual void move(sf::Time elapsed) = 0;

    bool collidable = false;
    // corresponds to the collision-box
    Vector2f collision_size = size;

    virtual bool check_collision(PhysObject &other);
};

#endif //INFLAMMABLE_PHYSOBJECT_H
