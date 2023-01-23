#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "UI/Button.hpp"

void toFight(Core::Event event) {
    event.game->activate("Fight");
}

void toMenu(Core::Event event) {
    event.game->activate("Menu");
}

void close(Core::Event event) {
    event.window->close();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 756), "Omega");
    window.setVerticalSyncEnabled(true);

    Core::Game game(&window);

    sf::Font font;
    font.loadFromFile("assets/RulerGold.ttf");
    sf::Text playText("Play", font, 24);
    playText.setFillColor(sf::Color::Black);

    sf::Text menuText("Menu", font, 24);
    menuText.setFillColor(sf::Color::Black);

    sf::Text closeText("Quit", font, 24);
    closeText.setFillColor(sf::Color::Black);

    UI::Button fightButton(sf::Vector2f(100, 50), sf::Vector2f(500,500), sf::Color::White, playText, &toFight);
    UI::Button menuButton(sf::Vector2f(100, 50), sf::Vector2f(500,500), sf::Color::White, menuText, &toMenu);
    UI::Button quitButton(sf::Vector2f(100, 50), sf::Vector2f(0,0), sf::Color::White, closeText, &close);

    Core::Scene menu(&game, std::string("Menu"));
    Core::Scene fight(&game, std::string("Fight"));

    menu.addObject(&fightButton);
    menu.addObject(&quitButton);
    fight.addObject(&menuButton);
    std::vector<Core::Scene*> scenes;

    scenes.push_back(&menu);
    scenes.push_back(&fight);

    game.addScenes(scenes);
    game.activate("Menu");

    game.run();

    return 0;
}
