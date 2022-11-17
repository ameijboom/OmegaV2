//
// Created by alwin on 11/14/22.
//
#include "UI/Button.hpp"
#include "SFML/Window/Mouse.hpp"

namespace UI {
    Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color hoverColor, sf::Text& text) : rect(size), text(text), hoverColor(hoverColor) {
        this->rect.setPosition(position);
        this->rect.setFillColor(color);
        this->rect.setOutlineColor(sf::Color::Black);

        updateText();
    }

    void Button::draw(sf::RenderTarget* target) const {
        target->draw(this->rect);
        target->draw(this->text);
    }

    sf::FloatRect Button::getBounds() const {
        return this->rect.getGlobalBounds();
    }

    void Button::onClick() {
        this->rect.setFillColor(this->hoverColor);
    }

    void Button::updateText() {
        auto size = this->rect.getSize();
        auto position = this->rect.getPosition();

        this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().width / 2.0f, this->text.getLocalBounds().height));
        this->text.setPosition(sf::Vector2f(position.x + size.x / 2.0f, position.y + size.y / 2.0f));
    }
}