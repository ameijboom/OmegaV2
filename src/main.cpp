#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "UI/Button.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 756), "Omega");
    window.setVerticalSyncEnabled(true);

    Core::Game game(&window);

    sf::Font font;
    font.loadFromFile("assets/RulerGold.ttf");
    sf::Text text("Button", font, 24);
    text.setFillColor(sf::Color::Black);

    UI::Button button(sf::Vector2f(100, 50), sf::Vector2f(0,0), sf::Color::White, sf::Color::Magenta, text);
    game.add(&button);
    game.run();

    return 0;
}
