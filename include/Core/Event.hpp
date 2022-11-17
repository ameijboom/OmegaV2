//
// Created by alwin on 11/17/22.
//

#pragma once

#include "SFML/Window.hpp"

namespace Core {
    class Event {
    public:
        sf::Window* window;

    public:
        Event(sf::Window* window);
    };
}
