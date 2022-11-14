//
// Created by alwin on 11/14/22.
//

#pragma once

#include "Object.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace UI {
    class Button : public sf::RectangleShape {
    private:
        sf::Color hoverColor;
        sf::Text& text;

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void setPosition(const sf::Vector2f& position);

    public:
        Button(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, sf::Text& text);
    };
}
