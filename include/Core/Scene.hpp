//
// Created by ameij on 1/16/2023.
//

#pragma once

#include <string>
#include <vector>
#include "Object.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"

namespace Core {
    class Scene {
    private:
        sf::RenderWindow *window;
        std::vector<Core::Object*> objects;
        Core::Game *game;
        sf::Text *title;
    public:
        std::string id;
        bool battle;

        Scene(Core::Game* game, std::string id, bool battle);
        void onClick(sf::Vector2f mousePos) const;
        void insertWindow(sf::RenderWindow *renderWindow);
        void render() const;
        void addObject(Core::Object* object);
        void addText(sf::Text* text);
        void addObjects(const std::vector<Core::Object*>& object_vec);
    };
}