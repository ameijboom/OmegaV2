//
// Created by ameij on 30/01/2023.
//
#include <utility>

#include "UI/Display.hpp";

namespace UI {
    Display::Display(sf::Vector2f size, sf::Vector2f position, std::string id, bool active) : id(std::move(id)), active(active) {
        this->rect = sf::RectangleShape(sf::Vector2f(size.x -2, size.y -2));
        this->rect.setPosition(position);
        this->rect.setFillColor(sf::Color::White);
        this->rect.setOutlineThickness(2.0f);
        this->rect.setOutlineColor(sf::Color::Black);
    }

    void Display::addText(UI::DisplayText *text) {
        this->texts.push_back(text);
    }

    void Display::toggle() {
        this->active = !this->active;
    }

    void Display::draw(sf::RenderTarget *target) const {
        target->draw(this->rect);

        for (auto &text : texts) {
            target->draw(text->text);
        }
    }
}