//
// Created by alwin on 11/14/22.
//
#include "Game.hpp"
#include "UI/Button.hpp"
#include "SFML/Window/Event.hpp"

namespace Core {
    Game::Game(sf::RenderWindow *window) {
        this->window = window;
        this->objects = std::vector<Core::Object*>();
    }

    void Game::handleOnClick(const sf::Vector2f mousePos) const {
        for (auto* object : objects) {
            if (object->getBounds().contains(mousePos)) {
                object->onClick();
            }
        }
    }

    void Game::run() const {
        while(window->isOpen()) {
            sf::Event event;

            while(window->pollEvent(event)) {
                switch(event.type) {
                    case sf::Event::EventType::Closed:
                        window->close();
                        break;
                    case sf::Event::MouseButtonReleased:
                        if (event.mouseButton.button != sf::Mouse::Button::Left) break;
                        handleOnClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                        break;
                }
            }

            window->clear();
            render();
            window->display();
        }
    }

    void Game::render() const {
        for (auto object : objects) {
            object->draw(window);
        }
    }

    void Game::add(Core::Object* object) {
        objects.push_back(object);
    }
}