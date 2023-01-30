#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include "Game.hpp"
#include "UI/Button.hpp"
#include "UI/Textbox.hpp"
#include "Entities/Entity.hpp"
#include "Battle.hpp"
#include "UI/Display.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void toFight(Core::Event event) {
    event.game->activate("Fight");
}

void toMenu(Core::Event event) {
    event.game->activate("Menu");
}

void toScores(Core::Event event) {
    event.game->activate("High Score");
}

void quit(Core::Event event) {
    event.window->close();
}

void attack(Core::Event event) {
    if (event.game->battle->turn == Core::Turn::Player) {
        auto &user = event.game->battle->player;
        auto &target = event.game->battle->currentEnemy;

        if(target != nullptr) event.game->battle->attack(user, target);
        event.game->battle->turn = Core::Turn::Enemy;

        if(target == nullptr) event.game->activate("Menu");
    }
}

void heal(Core::Event event) {
    if (event.game->battle->turn == Core::Turn::Player) {
        auto &user = event.game->battle->player;
        event.game->battle->heal(user);

        event.game->battle->turn = Core::Turn::Enemy;
    }
}

std::vector<int> getScores() {
    std::fstream file("assets/data.cmgt");
    json data = json::parse(file);
    std::vector<int> scores{};

    for (const auto& score : data["highscores"]) {
        scores.push_back(score);
    }

    return scores;
}

void writeScores(const std::vector<int>& scores) {
    std::ofstream file("assets/data.cmgt");
    json highScores;
    highScores["highscores"] = scores;

    file << highScores;
}

void eraseScores(Core::Event event) {
    event.game->scores = {};
    writeScores({0});
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 756), "Omega");
    window.setVerticalSyncEnabled(true);

    sf::Font font;
    font.loadFromFile("assets/retganon.ttf");
    sf::Text playText("Play", font, 30);
    playText.setFillColor(sf::Color::Black);

    sf::Text menuText("Menu", font, 30);
    menuText.setFillColor(sf::Color::Black);

    sf::Text attackText("Attack", font, 30);
    attackText.setFillColor(sf::Color::Black);

    sf::Text healText("Heal", font, 30);
    healText.setFillColor(sf::Color::Black);

    sf::Text quitText("Quit", font, 30);
    quitText.setFillColor(sf::Color::Black);

    sf::Text highScoreText("Scores", font, 30);
    highScoreText.setFillColor(sf::Color::Black);

    sf::Text highScoreEraseText("Erase", font, 30);
    highScoreEraseText.setFillColor(sf::Color::Black);

    sf::Text dialogText("You're gonna have a bad time", font, 30);
    dialogText.setFillColor(sf::Color::Black);

    UI::Button AttackButton(sf::Vector2f(100, 48), sf::Vector2f(1078,625), sf::Color::White, attackText, &attack);
    UI::Button DefendButton(sf::Vector2f(100, 48), sf::Vector2f(1185,625), sf::Color::White, healText, &heal);
    UI::Button fightButton(sf::Vector2f(100, 48), sf::Vector2f(450,756/2), sf::Color::White, playText, &toFight);
    UI::Button menuButton(sf::Vector2f(100, 48), sf::Vector2f(1078,680), sf::Color::White, menuText, &toMenu);
    UI::Button summaryButton(sf::Vector2f(100, 48), sf::Vector2f(1185,680), sf::Color::White, quitText, &quit);
    UI::Button HighScoreButton(sf::Vector2f(100, 48), sf::Vector2f(1280/2-50, 756/2), sf::Color::White, highScoreText, &toScores);
    UI::Button HighScoreErasureButton(sf::Vector2f(100, 48), sf::Vector2f(1280/2-100/2 + 200, 50), sf::Color::White, highScoreEraseText, &eraseScores);

    Entities::Entity Cynthia(sf::Vector2f(50, 250), 100.0f, "assets/sprites/templar.png");
    Entities::Entity fishbone(sf::Vector2f(1000, 1), 100.0f, "assets/sprites/fishbone.png");
    Entities::Entity eelWielder(sf::Vector2f(1000, 1), 100.0f, "assets/sprites/eelwielder.png");
    Entities::Entity dracoMachina(sf::Vector2f(1000, 1), 100.0f, "assets/sprites/dracomachina.png");

    UI::Textbox dialog(sf::Vector2f(1280, 156), sf::Vector2f(0, 600), dialogText);
    Core::Battle battle(&dialog, &Cynthia);

    Core::Game game(&window, &battle);

    Core::Scene menu(&game, std::string("Menu"), false);
    Core::Scene highScoreScene(&game, std::string("High Score"), false);

    battle.addEnemy(&fishbone, "Fishbone");
    battle.addEnemy(&eelWielder, "Eel Wielder");
    battle.addEnemy(&dracoMachina, "Draco Machina");

    Core::Scene fight(&game, std::string("Fight"), true);
    Core::Scene gameOver(&game, std::string("Game Over"), false);
    UI::Display gameOverDisplay(sf::Vector2f(500, 250), sf::Vector2f(1280/2-500/2, 756/2-250/2), "Game Over", true);
    auto gameOverText = UI::DisplayText("Game Over", sf::Vector2f(1280/2-500/2 + 200, 756/2-250/2), "assets/retganon.ttf");
    gameOverDisplay.addText(&gameOverText);
    gameOver.addObject(&gameOverDisplay);

    UI::Display enemyHealth(sf::Vector2f(150, 50), sf::Vector2f(0, 0), "Enemy", true);
    UI::Display playerHealth(sf::Vector2f(150, 50), sf::Vector2f(1130, 550), "Player", true);
    UI::Display highScoreDisplay(sf::Vector2f(300, 600), sf::Vector2f(1280/2-300/2, 756/2-600/2), "High Scores", true);

    auto enemyHealthText = UI::DisplayText("HP", sf::Vector2f(10, 10),"assets/retganon.ttf");
    auto playerHealthText = UI::DisplayText("HP", sf::Vector2f(1140, 560),"assets/retganon.ttf");

    std::vector<UI::DisplayText> highScores;

    std::vector<int> scores = getScores();
    game.scores = &scores;

    for (int i = 0; i < 5; i++) {
        highScores.emplace_back(std::to_string(scores[i]), sf::Vector2f(1280/2-50, 756/2-100-i*10), "assets/RulerGold.ttf");
    }

    for (auto score : highScores) {
//        score.UpdateText("Test");
        highScoreDisplay.addText(&score);
    }

    enemyHealth.addText(&enemyHealthText);
    playerHealth.addText(&playerHealthText);

    battle.addDisplay("Enemy", &enemyHealth);
    battle.addDisplay("Player", &playerHealth);

    fight.addObject(&dialog);
    fight.addObject(&AttackButton);
    fight.addObject(&menuButton);
    fight.addObject(&summaryButton);
    fight.addObject(&DefendButton);
    menu.addObject(&fightButton);
    menu.addObject(&HighScoreButton);
    gameOver.addObject(&HighScoreButton);
    highScoreScene.addObject(&highScoreDisplay);
    highScoreScene.addObject(&HighScoreErasureButton);
    highScoreScene.addObject(&menuButton);
    std::vector<Core::Scene*> scenes;

    scenes.push_back(&menu);
    scenes.push_back(&fight);
    scenes.push_back(&gameOver);
    scenes.push_back(&highScoreScene);

    game.addScenes(scenes);
    game.activate("Menu");

    game.run();

    return 0;
}
