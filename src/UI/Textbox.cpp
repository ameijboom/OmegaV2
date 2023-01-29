//
// Created by alwin on 29/01/23.
//

#include "UI/Textbox.hpp"

class RenderTarget;

namespace UI {
    Textbox::Textbox(sf::Vector2f size, sf::Vector2f position, sf::Text &text) : rect(size), text(text) {
        this->rect.setPosition(position);
        this->rect.setFillColor(sf::Color::White);
        this->rect.setOutlineColor(sf::Color::Black);

        updateText();
    }

    void Textbox::draw(sf::RenderTarget* target) const {
        target->draw(this->rect);
        target->draw(this->text);
    }

    sf::FloatRect Textbox::getBounds() const {
        return this->rect.getGlobalBounds();
    }

    void Textbox::updateText() {
        auto size = this->rect.getSize();
        auto position = sf::Vector2f(this->rect.getPosition().x + size.x / 2.0f, this->rect.getPosition().y + size.y / 2.0f);

        this->text.setPosition(sf::Vector2f(position.x - size.x / 2.0f + 2.0f, position.y - size.y / 2.0f + 2.0f));
    }
}