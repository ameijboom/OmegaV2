//
// Created by alwin on 11/14/22.
//

#pragma once

#include "SFML/Graphics/Drawable.hpp"

namespace Core {
    class Object {
    public:
        virtual void draw(sf::RenderTarget* target) const {}
        virtual void onClick() {}
        virtual sf::FloatRect getBounds() const {}
    };
}
