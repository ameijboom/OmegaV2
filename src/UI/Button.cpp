//
// Created by alwin on 11/14/22.
//
#include "UI/Button.hpp"
#include "SFML/Window/Mouse.hpp"

namespace UI {
    Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Text& text, void(*click)(Core::Event)) : rect(size), text(text) {
        this->rect.setPosition(position);
        this->rect.setFillColor(color);
        this->rect.setOutlineColor(sf::Color::Black);

        this->click = click;

        updateText();
    }

    void Button::draw(sf::RenderTarget* target) const {
        target->draw(this->rect);
        target->draw(this->text);
    }

    sf::FloatRect Button::getBounds() const {
        return this->rect.getGlobalBounds();
    }

    void Button::onClick(Core::Event event) {
        this->click(event);
    }

    void Button::updateText() {
        auto size = this->rect.getSize();
        auto position = this->rect.getPosition();

        this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds().width / 2.0f, this->text.getLocalBounds().height));
        this->text.setPosition(sf::Vector2f(position.x + size.x / 2.0f, position.y + size.y / 2.0f));
    }
}