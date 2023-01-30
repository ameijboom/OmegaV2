//
// Created by alwin on 29/01/23.
//

#include <cmath>
#include <cstring>
#include "Battle.hpp"

namespace Core {
    Battle::Battle(UI::Textbox *dialog,Entities::Entity* player) : dialog(dialog), player(player) {}

    std::string Battle::getEnemyFromPointer(Entities::Entity *enemy) {
        for (auto &it : this->enemies) {
            if (it.second == enemy) return it.first;
        }
        return {};
    }

    void Battle::addEnemy(Entities::Entity *enemy, const std::string& id) {
        if (!this->enemies.contains(id)) {
            this->enemies.insert({id, enemy});
        } else {
            this->enemies[id] = enemy;
        }

        if (currentEnemy == nullptr) this->currentEnemy = enemy;
    }

    void Battle::addEnemies(const std::map<std::string, Entities::Entity *>& enemyMap) {
        for (const auto& enemy : enemyMap) {
            Battle::addEnemy(enemy.second, enemy.first);
        }
    }

    void Battle::attack(Entities::Entity *User, Entities::Entity *Target) {
        auto atk = User->attack - Target->defense;

        if (atk <= 0) atk = 1;
        Target->hp -= atk;

        std::string user = (User == this->player) ? "Player" : Battle::getEnemyFromPointer(User);

        dialog->notify(user + " dealt " + std::to_string((int)atk) + " damage!");

        if (Target->hp <= 0 && Target != this->player) {
            dialog->notify(Battle::getEnemyFromPointer(Target) + " fainted!");

            this->enemies.erase(Battle::getEnemyFromPointer(Target));
            if (!this->enemies.empty()) {
                this->currentEnemy = enemies.begin()->second;
            } else {
                this->currentEnemy = nullptr;
            }
        }

        wait = true;
    }


    void Battle::heal(Entities::Entity *User) {
        auto heal = std::ceil((User->attack + User->defense) / 2.0f);
        if (User->hp + heal > User->maxHp) User->hp = User->maxHp;
        else User->hp += heal;

        std::string user = (User == this->player) ? "Player" : Battle::getEnemyFromPointer(User);

        dialog->notify(user + " healed " + std::to_string((int)heal) + " HP");

        wait = true;
    }

    void Battle::doNothing() {
        dialog->notify("Your enemy just seems to be loafing about.");
    }

    void Battle::draw(sf::RenderTarget *target) const {
        this->player->draw(target);
        if (this->currentEnemy != nullptr) this->currentEnemy->draw(target);

        for (auto &display : displays) {
            target->draw(display.second->rect);
            if (strcmp(display.first.c_str(), "Player") == 0) {
                display.second->texts.front()->UpdateText("HP: " + std::to_string((int)player->hp));
                display.second->draw(target);
            } else if (strcmp(display.first.c_str(), "Enemy") == 0 && currentEnemy != nullptr) {
                display.second->texts.front()->UpdateText("HP: " + std::to_string((int)currentEnemy->hp));
                display.second->draw(target);
            }
        }
    }

    void Battle::EnemyTurn() {
        if (turn == Core::Turn::Enemy && currentEnemy != nullptr) {
            turn = Core::Turn::Player;

            srand((unsigned) time(nullptr));

            switch((rand() % 3) + 1) {
                case 1:
                    doNothing();
                    break;
                case 2:
                    Battle::attack(currentEnemy, player);
                    break;
                case 3:
                    Battle::heal(currentEnemy);
                    break;
            }
        }
    }

    void Battle::addDisplay(std::string key, UI::Display *value) {
        this->displays.insert({key, value});
    }
}