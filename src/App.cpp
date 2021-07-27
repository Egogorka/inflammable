//
// Created by Meevere on 5/24/2021.
//

#include "App.h"

App::App() {
    resolution = RESOLUTION;
    window.create(sf::VideoMode(resolution.x, resolution.y), "Test", sf::Style::Default);
    window.setFramerateLimit(60);
}

void App::before_loop() {
    player = Player(Vector2f(50,50));
    game_objects.push_back(&player);
}

void App::on_loop() {
    auto elapsed = clock.restart();
    window.clear(sf::Color::Black);

    player.move(elapsed);

    for( auto object : game_objects ){
        window.draw(*object);
    }

    window.display();
}

void App::on_event(sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            std::cout << "click!\n";
        }
    }
}

void App::run() {
    before_loop();
    while (window.isOpen()){
        on_loop();
        sf::Event event{};
        while (window.pollEvent(event))
            on_event(event);
    }
}