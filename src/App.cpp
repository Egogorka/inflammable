//
// Created by Meevere on 5/24/2021.
//

#include "App.h"
#include "GameObjects/Wall/Wall.h"

App::App() {
    resolution = RESOLUTION;
    window.create(sf::VideoMode(resolution.x, resolution.y), "Test", sf::Style::Default);
    window.setFramerateLimit(60);
}

void App::before_loop() {
    player = new Player(Vector2f(50,50));
    phys_object.push_back(new Wall(Vector2f(150,150), Vector2f(200,5)));
    phys_object.push_back(new Wall(Vector2f(300,150), Vector2f(60,60)));
    phys_object.push_back(player);
}

App::~App() {
    for( auto object : phys_object ){
        delete object;
    }
}

void App::on_loop() {
    auto elapsed = clock.restart();
    window.clear(sf::Color::Black);

    player->move(elapsed);

    for( auto object : phys_object ){
        window.draw(*object);

        if( player == object ) continue;
        player->collide(*object);
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