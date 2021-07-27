//
// Created by Meevere on 5/30/2021.
//

#include "Player.h"
using sf::Keyboard;

Player::Player(Vector2f pos) {
    position = pos;
    size = Vector2f(30,30);
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