//
// Created by alwin on 11/14/22.
//
#include <thread>
#include <iostream>
#include "Game.hpp"
#include "UI/Button.hpp"
#include "SFML/Window/Event.hpp"


namespace Core {
    Game::Game(sf::RenderWindow *window, Core::Battle* battle) : battle(battle){
        this->window = window;
        this->scenes = std::vector<Core::Scene*>();
        this->activeScene = nullptr;
    }

    void Game::handleOnClick(const sf::Vector2f mousePos) const {
        activeScene->onClick(mousePos);
    }

    void Game::run() {
        while(window->isOpen()) {
            if (battle->wait) {
                std::this_thread::sleep_for(std::chrono::seconds (1));
                battle->wait = false;
            }
            sf::Event event{};

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
            if (activeScene->battle) {
                battle->EnemyTurn();
                if(battle->player->hp <= 0) {
                    Game::activate("Game Over");
                    std::cout << "Should Switch" << std::endl;
                }
            }
            window->display();
        }
    }

    void Game::activate(std::string id) {
        for (auto* scene : scenes) {
            if (scene->id == id) {
                scene->insertWindow(window);
                activeScene = scene;
            }
        }
    }

    void Game::render() const {
        if (activeScene != nullptr) {
            activeScene->render();
            if (activeScene->battle) {
                battle->draw(window);
            }
        }
    }

    void Game::addScene(Core::Scene* scene) {
        scenes.push_back(scene);
    }

    void Game::addScenes(std::vector<Core::Scene *> scenes) {
        for (auto* scene : scenes) {
            Game::addScene(scene);
        }
    }
}