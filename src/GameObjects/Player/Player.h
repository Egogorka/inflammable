//
// Created by Meevere on 5/30/2021.
//

#ifndef INFLAMMABLE_PLAYER_H
#define INFLAMMABLE_PLAYER_H

#include <SFML/Graphics.hpp>
using sf::Vector2i, sf::Vector2f;
using sf::RenderTarget, sf::RenderStates;

class Player: public sf::Drawable {
protected:
    Vector2f pos;

public:
    explicit Player();
    explicit Player(Vector2f _pos);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //INFLAMMABLE_PLAYER_H
