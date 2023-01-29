#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "UI/Button.hpp"
#include "UI/Textbox.hpp"

void toFight(Core::Event event) {
    event.game->activate("Fight");
}

void toMenu(Core::Event event) {
    event.game->activate("Menu");
}

void close(Core::Event event) {
    event.window->close();
}

void random(Core::Event event) {
    printf("Lmao\n");
}

int main() {

    sf::Text menuText("Menu", font, 24);
    menuText.setFillColor(sf::Color::Black);

    sf::Text closeText("Quit", font, 24);
    closeText.setFillColor(sf::Color::Black);

    sf::Text randomText("Test", font, 24);
    randomText.setFillColor(sf::Color::Black);

    sf::Text dialogText("You're gonna have a bad time", font, 22);
    dialogText.setFillColor(sf::Color::Black);

    UI::Button fightButton(sf::Vector2f(100, 50), sf::Vector2f(1080,630), sf::Color::White, playText, &toFight);
    UI::Button menuButton(sf::Vector2f(100, 50), sf::Vector2f(1180,630), sf::Color::White, menuText, &toMenu);
    UI::Button quitButton(sf::Vector2f(100, 50), sf::Vector2f(1080,680), sf::Color::White, closeText, &close);
    UI::Button randomButton(sf::Vector2f(100, 50), sf::Vector2f(1180,680), sf::Color::White, randomText, &random);


    UI::Textbox dialog(sf::Vector2f(1280, 156), sf::Vector2f(0, 600), dialogText);

    Core::Scene menu(&game, std::string("Menu"));
    Core::Scene fight(&game, std::string("Fight"));

    fight.addObject(&dialog);
    fight.addObject(&quitButton);
    fight.addObject(&menuButton);
    fight.addObject(&fightButton);
    fight.addObject(&randomButton);
    menu.addObject(&fightButton);
    std::vector<Core::Scene*> scenes;

    scenes.push_back(&menu);
    scenes.push_back(&fight);

    game.addScenes(scenes);
    game.activate("Menu");

    game.run();

    return 0;
}
