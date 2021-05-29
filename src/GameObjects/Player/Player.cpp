//
// Created by Meevere on 5/30/2021.
//

#include "Player.h"

Player::Player() {pos = Vector2f(0,0);}
Player::Player(Vector2f _pos): pos(_pos) {};

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::RectangleShape rect(Vector2f(30,30));
    Vector2f real_pos = pos - Vector2f(15,15);
    rect.setPosition(real_pos);

    target.draw(rect);
}