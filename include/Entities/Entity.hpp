//
// Created by alwin on 29/01/23.
//

#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace Entities {
    class Entity {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        float level;
    public:
        float hp;
        float attack;
        float defense;

    public:
        Entity(float xp, std::string texture);
        void Render();
        void Destroy();
    };
}