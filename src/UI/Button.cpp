//
// Created by alwin on 11/14/22.
//
#include "UI/Button.hpp"
#include "SFML/Window/Mouse.hpp"

namespace UI {
    Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, sf::Text& text) : sf::RectangleShape(size), text(text), hoverColor(hoverColor) {
        setPosition(position);
        setFillColor(color);
        setOutlineColor(sf::Color::Black);
    }

    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(static_cast<sf::RectangleShape>(*this), states);
        target.draw(this->text, states);
    }

    void Button::setPosition(const sf::Vector2f& position) {
        auto size = this->getSize();

        this->text.setPosition(sf::Vector2f(position.x + size.x / 2.0f, position.y + size.y / 2.0f));
        this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().width / 2.0f, this->text.getLocalBounds().height));
        sf::RectangleShape::setPosition(position);
    };
}