//
// Created by alwin on 29/01/23.
//

#pragma once

#include <string>
#include <map>
#include "Entities/Entity.hpp"
#include "UI/Textbox.hpp"

namespace Core {
    class Battle {
    private:
        std::map<std::string, Entities::Entity*> enemies;
        Entities::Entity* player;
        Entities::Entity* currentEnemy;
        UI::Textbox* dialog;
    };
}