//
// Created by alwin on 11/14/22.
//

#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "Object.hpp"

namespace Core {
    class Game {
    private:
        sf::RenderWindow *window;
        std::vector<Core::Object*> objects;

    private:
        void render() const;
        void handleOnClick(const sf::Vector2f mousePos) const;

    public:
        explicit Game(sf::RenderWindow *window);
        void run() const;
        void add(Core::Object *object);
    };
}
