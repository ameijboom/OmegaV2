//
// Created by alwin on 29/01/23.
//

#include <utility>
#include <iostream>
#include <chrono>
#include <thread>

#include "Entities/Entity.hpp"

namespace Entities {
    Entity::Entity(sf::Vector2f position, float xp, std::string texturePath) {
        this->level = xp / 10;
        float numbers[3] = {};

        std::cout << texturePath << std::endl;

        srand((unsigned) time(nullptr));

        for (float & number : numbers) {
            number = 10 + rand() % 20;
        }

        this->hp = numbers[0];
        this->maxHp = numbers[0];
        this->attack = numbers[1] + 5;
        this->defense = numbers[2];

        if (!this->texture.loadFromFile(texturePath)) {}
        this->sprite = sf::Sprite(this->texture);

        this->sprite.setPosition(position);
        this->sprite.setScale(4.0f, 4.0f);
    }

    void Entity::draw(sf::RenderTarget *target) const {
        target->draw(this->sprite);
    }

    void Entity::Destroy() {
        this->hp = 0;
        this->attack = 0;
        this->defense = 0;
        this->level = 0;
    }
}