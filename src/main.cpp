#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Omega");
    window.setVerticalSyncEnabled(true);

    Core::Game game(&window);

    game.run();

    return 0;
}
