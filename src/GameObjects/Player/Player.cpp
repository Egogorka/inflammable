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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity += Vector2f(-5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity += Vector2f(5,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        velocity += Vector2f(0,-5);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        velocity += Vector2f(0,5);
}

/**
 * Function that nulls first parameter if it
 * has the different sign with second and returns the result
 */
float qwerty(float a, float b){
   return a*b > 0 ? a : 0;
}

enum Direction: int {Top, Left, Right, Bottom};

Direction switch_dir( Direction dir){
    switch(dir){
        case Direction::Top: return Direction::Bottom;
        case Direction::Bottom: return Direction::Top;
        case Direction::Left: return Direction::Right;
        case Direction::Right: return Direction::Left;
    }
}

Direction position_check(Player& player, PhysObject& obj){
    auto pos = player.position + player.size/2.f;

    std::vector<float> dist(4);

    dist[Direction::Left] = fabsf(pos.x - obj.position.x);
    dist[Direction::Right] = fabsf(pos.x - obj.position.x - obj.size.x);
    dist[Direction::Top] = fabsf(pos.y - obj.position.y);
    dist[Direction::Bottom] = fabsf(pos.y - obj.position.y - obj.size.y);

    float min; int min_key = -1;
    for(int i=0; i<4; i++){
        if( min > dist[i] or min_key == -1){
            min = dist[i]; min_key = i;
        }
    }
    return Direction(min_key);
}

Direction velocity_check(Player& player){

    std::vector<float> dist(4);
    dist[Direction::Left] = qwerty(player.velocity.x, -1);
    dist[Direction::Right] = qwerty(player.velocity.x, 1);
    dist[Direction::Top] = qwerty(player.velocity.y, -1);
    dist[Direction::Bottom] = qwerty(player.velocity.y, 1);

    float min = -1; int min_key = -1;
    for(int i=0; i<4; i++){
        if( min > dist[i] or min_key == -1){
            min = dist[i]; min_key = i;
        }
    }
    return Direction(min_key);
}

void Player::collide(PhysObject& obj) {
    if(!this->check_collision(obj)) return;

    std::cout << "collision!";

    Direction pos_dir = position_check(*this, obj);
    Direction vel_dir = velocity_check(*this);

    std::cout << pos_dir << '\n';
//    if( vel_dir != pos_dir ) pos_dir = switch_dir(pos_dir);
//    std::cout << pos_dir << '\n';

    switch(pos_dir) {
        case Direction::Right:
            position.x = obj.position.x + obj.size.x;
            velocity.x = qwerty(velocity.x, 1);
            break;
        case Direction::Left:
            position.x = obj.position.x - size.x;
            velocity.x = qwerty(velocity.x, -1);
            break;
        case Direction::Bottom:
            position.y = obj.position.y + obj.size.y;
            velocity.y = qwerty(velocity.y, 1);
            break;
        case Direction::Top:
            position.y = obj.position.y - size.y;
            velocity.y = qwerty(velocity.y, -1);
            break;
    }
}