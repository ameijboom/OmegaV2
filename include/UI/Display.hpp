//
// Created by ameij on 30/01/2023.
//

#pragma once

#include "Object.hpp"
#include "DisplayText.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

namespace UI {
    class Display : public Core::Object {
    public:
        std::string id;
        bool active = false;
        std::vector<UI::DisplayText*> texts;
        sf::RectangleShape rect;

    public:
        Display(sf::Vector2f size, sf::Vector2f position, std::string id, bool active);

        void addText(UI::DisplayText *text);
        void toggle();
        void draw(sf::RenderTarget *target) const override;
    };
}