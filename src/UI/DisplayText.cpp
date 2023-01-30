//
// Created by ameij on 30/01/2023.
//
#include "UI/DisplayText.hpp"

namespace UI {
    DisplayText::DisplayText(const std::string& text, sf::Vector2f position, const std::string& fontPath) {
        this->font.loadFromFile(fontPath);
        this->text = sf::Text(text, this->font, 30);
        this->text.setFillColor(sf::Color::Black);
        this->text.setPosition(position);
    }

    void DisplayText::UpdateText(std::string newText) {
        this->text.setString(newText);
    }


}