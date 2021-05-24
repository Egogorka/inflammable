//
// Created by Meevere on 5/23/2021.
//

#ifndef INFLAMMABLE_APP_H
#define INFLAMMABLE_APP_H

#include <SFML/Graphics.hpp>

using sf::Vector2f;

#define RESOLUTION_HEIGHT 800
#define RESOLUTION_WIDTH 800

#define RESOLUTION Vector2f(RESOLUTION_WIDTH, RESOLUTION_HEIGHT)

class App {
    Vector2f resolution;
    sf::RenderWindow window;
public:
    App();

    void run();

protected:
    void before_loop();
    void on_loop();
    void on_event(sf::Event& event);
};

#endif //INFLAMMABLE_APP_H
