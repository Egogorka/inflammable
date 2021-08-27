//
// Created by Meevere on 7/24/2021.
//

#include "PhysObject.h"
#include <iostream>

void minkowski_difference(const PhysObject &a, const PhysObject &b, sf::Vector2f &pos1, sf::Vector2f &pos2){
    auto size1 = a.collision_size + b.collision_size;
    pos1 = a.position - b.position - b.collision_size;
    pos2 = pos1 + size1;
}

bool PhysObject::check_collision(const PhysObject &other) {
    //using the method of minkowski difference
//    std::cout << collision_size.x << '|' << collision_size.y << '\n';
//    std::cout << other.collision_size.x << '|' << other.collision_size.y << '\n';
    sf::Vector2f pos1, pos2;
    minkowski_difference(*this, other, pos1, pos2);
    //std::cout << pos1.x << '|' << pos1.y << ' ' << pos2.x << '|' << pos2.y << '\n';
    return (pos1.x < 0) and (pos1.y < 0) and (pos2.x > 0) and (pos2.y > 0);
}

bool PhysObject::check_collision(const PhysObject &other, PhysObject::Axis axis) {
    sf::Vector2f pos1, pos2;
    minkowski_difference(*this, other, pos1, pos2);
    return axis == Axis::X_axis
        ? (pos1.x < 0) and (pos2.x > 0)
        : (pos1.y < 0) and (pos2.y > 0);
}


void PhysObject::move(sf::Time elapsed){
    auto pre_vel = velocity;
    prev_position = position;
    position += velocity * float(elapsed.asMilliseconds())/100.f;
    velocity += acceleration * float(elapsed.asMilliseconds())/100.f;
    acceleration = -friction * pre_vel;
}