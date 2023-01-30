//
// Created by alwin on 29/01/23.
//

#pragma once

#include <string>
#include <map>
#include "Entities/Entity.hpp"
#include "UI/Textbox.hpp"
#include "Turn.hpp"
#include "UI/Display.hpp"

namespace Core {
    class Battle {
    private:
        std::map<std::string, Entities::Entity*> enemies{};
        UI::Textbox* dialog;

    public:
        Entities::Entity* player{};
        Entities::Entity* currentEnemy = nullptr;
        Core::Turn turn = Core::Turn::Player;
        std::map<std::string, UI::Display*> displays{};
        bool wait = false;

    private:
        std::string getEnemyFromPointer(Entities::Entity* enemy);

    public:
        Battle(UI::Textbox* dialog, Entities::Entity* player);
        void addEnemy(Entities::Entity* enemy, const std::string& id);
        void addEnemies(const std::map<std::string, Entities::Entity*>& enemies);
        void addDisplay(std::string key, UI::Display* value);
        void attack(Entities::Entity* User, Entities::Entity* Target);
        void heal(Entities::Entity* User);
        void doNothing();
        void draw(sf::RenderTarget* target) const;
        void EnemyTurn();
    };

}