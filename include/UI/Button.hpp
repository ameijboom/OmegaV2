//
// Created by alwin on 11/14/22.
//

#pragma once

#include "Object.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Event.hpp"

namespace UI {
class Button : public Core::Object {
    private:
        sf::Text& text;
        sf::RectangleShape rect;
        void (*click)(Core::Event);

    private:
        void updateText();

    public:
        Button(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Text& text, void (*click)(Core::Event));
        void draw(sf::RenderTarget* target) const override;
        sf::FloatRect getBounds() const override;
        void onClick(Core::Event event) override;
    };
}
