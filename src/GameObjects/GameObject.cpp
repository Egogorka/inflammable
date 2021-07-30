//
// Created by Meevere on 7/27/2021.
//

#include "GameObject.h"

void GameObject::draw(RenderTarget &target, RenderStates states) const {
    if (hidden) return;

    sf::RectangleShape rect(size);
    rect.setFillColor(color);
    Vector2f real_pos = position;
    rect.setPosition(real_pos);

    target.draw(rect);
}