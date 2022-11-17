#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "UI/Button.hpp"

void close(Core::Event event) {
    event.window->close();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 756), "Omega");
    window.setVerticalSyncEnabled(true);

    Core::Game game(&window);

    sf::Font font;
    font.loadFromFile("assets/RulerGold.ttf");
    sf::Text text("Quit", font, 24);
    text.setFillColor(sf::Color::Black);

    UI::Button button(sf::Vector2f(100, 50), sf::Vector2f(0,0), sf::Color::White, text, &close);
    game.add(&button);
    game.run();

    return 0;
}
