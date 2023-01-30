//
// Created by alwin on 29/01/23.
//

#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "Object.hpp"

namespace Entities {
    class Entity : public Core::Object {
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        float level;
    public:
        float hp;
        float maxHp;
        float attack;
        float defense;

    public:
        Entity(sf::Vector2f position, float xp, std::string texturePath);
        virtual void draw(sf::RenderTarget* target) const override;
        void Destroy();
    };
}