//
// Created by ameij on 1/16/2023.
//


#include "Scene.hpp"

#include <utility>

namespace Core {
    Scene::Scene(Core::Game* game, std::string id, bool battle) : id(std::move(id)), game(game), battle(battle) {
        this->objects = std::vector<Core::Object*>();
        this->window = nullptr;
    }

    void Scene::insertWindow(sf::RenderWindow *renderWindow) {
        window = renderWindow;
    }

    void Scene::render() const {
        for (auto object : objects) {
            object->draw(window);
        }
    }

    void Scene::onClick(const sf::Vector2f mousePos) const {
        for (auto* object : objects) {
            if (object->getBounds().contains(mousePos)) {
                object->onClick(Core::Event(window, game));
            }
        }
    }

    void Scene::addObject(Core::Object *object) {
        objects.push_back(object);
    }

    void Scene::addObjects(const std::vector<Core::Object *>& object_vec) {
        for (auto* object : object_vec) {
            Scene::addObject(object);
        }
    }

    void Scene::addText(sf::Text *text) {
        title = text;
    }
}