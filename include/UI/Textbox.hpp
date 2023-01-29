//
// Created by alwin on 29/01/23.
//

#pragma once

#include "Object.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

namespace UI {
class Textbox : public Core::Object {
    private:
        sf::Text& text;
        sf::RectangleShape rect;

    private:
        void updateText();

    public:
        Textbox(sf::Vector2f size, sf::Vector2f position, sf::Text& text);
        void draw(sf::RenderTarget* target) const override;
        sf::FloatRect getBounds() const override;
    };
}