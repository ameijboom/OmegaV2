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
        std::vector<sf::Shape*> objects;

    private:
        void render() const;

    public:
        explicit Game(sf::RenderWindow *window);
        void run() const;
        void add(sf::Shape *shape);
    };
}
