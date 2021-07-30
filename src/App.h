//
// Created by Meevere on 5/23/2021.
//

#ifndef INFLAMMABLE_APP_H
#define INFLAMMABLE_APP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "GameObjects/Player/Player.h"

using sf::Vector2f;

#define RESOLUTION_HEIGHT 800
#define RESOLUTION_WIDTH 800

#define RESOLUTION Vector2f(RESOLUTION_WIDTH, RESOLUTION_HEIGHT)

class App {
public:
    App();
    ~App();
    void run();

protected:
    Vector2f resolution;
    sf::RenderWindow window;
    sf::Clock clock;

    Player* player;
    std::list<PhysObject*> phys_object;

    void before_loop();
    void on_loop();
    void on_event(sf::Event& event);
};

#endif //INFLAMMABLE_APP_H
