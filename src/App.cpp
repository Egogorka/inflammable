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

}

void App::on_loop() {
    window.clear(sf::Color::Black);
    window.display();
}

void App::on_event(sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
//    if (event.type == sf::Event::MouseButtonPressed){
//        if(event.mouseButton.button == sf::Mouse::Left){
//            std::cout << "click!\n";
//            table.click(Vector2f(event.mouseButton.x,event.mouseButton.y));
//        }
//    }
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