//
// Created by Meevere on 7/13/2021.
//

#ifndef INFLAMMABLE_GAMEOBJECT_H
#define INFLAMMABLE_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
using sf::Vector2i, sf::Vector2f;
using sf::RenderTarget, sf::RenderStates;

class GameObject: public sf::Drawable {
public:
    Vector2f position;
    Vector2f size = Vector2f(0,0);

    // shows if object is hidden
    bool hidden = false;
    sf::Color color = sf::Color::Green;
    void draw(RenderTarget &target, RenderStates states) const override;

    // stack ordering:
    // objects with lower z-index are displayed beneath ones that have higher index
    // CURRENTLY NOT IMPLEMENTED
    int z_index = 0;
};

#endif //INFLAMMABLE_GAMEOBJECT_H
