//
// Created by Meevere on 7/24/2021.
//

#include "PhysObject.h"
#include <iostream>

bool PhysObject::check_collision(PhysObject &other) {
    //using the method of minkowski difference
//    std::cout << collision_size.x << '|' << collision_size.y << '\n';
//    std::cout << other.collision_size.x << '|' << other.collision_size.y << '\n';

    auto size1 = this->collision_size + other.collision_size;
    auto pos1 = this->position - other.position - other.collision_size;
    auto pos2 = pos1 + size1;
//    std::cout << pos1.x << '|' << pos1.y << ' ' << pos2.x << '|' << pos2.y << '\n';
    return (pos1.x < 0) and (pos1.y < 0) and (pos2.x > 0) and (pos2.y > 0);
}

void PhysObject::move(sf::Time elapsed){
    auto pre_vel = velocity;
    position += velocity * float(elapsed.asMilliseconds())/100.f;
    velocity += acceleration * float(elapsed.asMilliseconds())/100.f;
    acceleration = -friction * pre_vel;
}