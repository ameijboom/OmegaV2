//
// Created by alwin on 11/14/22.
//

#pragma once

#include "SFML/Graphics/Drawable.hpp"
#include "Event.hpp"

namespace Core {
    class Object {
    public:
        virtual void draw(sf::RenderTarget* target) const {}
        virtual void onClick(Core::Event event) {}
        virtual sf::FloatRect getBounds() const {}
    };
}
