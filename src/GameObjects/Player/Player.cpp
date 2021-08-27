//
// Created by Meevere on 5/30/2021.
//

#include "Player.h"
#include <cmath>
#include <vector>
using sf::Keyboard;

Player::Player(Vector2f pos) {
    position = pos;
    collision_size = size = Vector2f(30,30);
    friction = 0.5;
}
Player::Player(): Player(Vector2f(0,0)) {}

void Player::move(sf::Time elapsed) {
    PhysObject::move(elapsed);
    acceleration += Vector2f(0,30);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity += Vector2f(-5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity += Vector2f(5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        velocity += Vector2f(0,-5);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        velocity += Vector2f(0,5);
}

void Player::collide(PhysObject& obj) {
    if(check_collision(obj)){
        auto cur_position = position;
        auto dr = cur_position - prev_position;
        //check y-axis
        position.x = prev_position.x;
        if(!check_collision(obj)){
            if(dr.x > 0)    position.x = obj.position.x - size.x;
            else            position.x = obj.position.x + obj.collision_size.x;
            velocity.x = 0;
        } else {
            position.x = cur_position.x;
            //check x-axis
            position.y = prev_position.y;
            if(!check_collision(obj)){
                if(dr.y > 0)    position.y = obj.position.y - size.y;
                else            position.y = obj.position.y + obj.collision_size.y;
                velocity.y = 0;
            } else position.y = cur_position.y;
        }
    }
}