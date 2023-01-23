//
// Created by ameij on 1/16/2023.
//

#pragma once

#include <string>
#include <vector>
#include "Object.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Core {
    class Scene {
    private:
        sf::RenderWindow *window;
        std::vector<Core::Object*> objects;
        Core::Game *game;
    public:
        std::string id;

        Scene(Core::Game* game, std::string id);
        void onClick(sf::Vector2f mousePos) const;
        void insertWindow(sf::RenderWindow *renderWindow);
        void render() const;
        void addObject(Core::Object* object);
        void addObjects(const std::vector<Core::Object*>& object_vec);
    };
}