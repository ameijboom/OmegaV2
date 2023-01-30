//
// Created by ameij on 30/01/2023.
//

#pragma once

#include "SFML/Graphics/Text.hpp"

namespace UI {
    class DisplayText {
    private:
        sf::Font font;
    public:
        sf::Text text;
        sf::Vector2f position;

    public:
        DisplayText(const std::string& text, sf::Vector2f position, const std::string& fontPath);
        void UpdateText(std::string newText);
    };
}
