//
// Created by alwin on 11/14/22.
//
#include "Game.hpp"
#include "UI/Button.hpp"
#include "SFML/Window/Event.hpp"

namespace Core {
    Game::Game(sf::RenderWindow *window) {
        this->window = window;
        this->objects = std::vector<sf::Shape*>();
    }

    void Game::run() const {
        while(window->isOpen()) {
            sf::Event event;

            while(window->pollEvent(event)) {
                if (event.type == sf::Event::Closed) window->close();
            }

            window->clear();
            render();
            window->display();
        }
    }

    void Game::render() const {
        for (sf::Shape* shape : objects) {
            window->draw(*shape);
        }
    }

    void Game::add(sf::Shape *shape) {
        objects.push_back(shape);
    }
}