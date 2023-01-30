//
// Created by alwin on 11/14/22.
//

#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "Object.hpp"
#include "Scene.hpp"
#include "Battle.hpp"

namespace Core {
    class Game {
    private:
        sf::RenderWindow *window;
        std::vector<Core::Scene*> scenes;
        Core::Scene *activeScene;

    public:
        Core::Battle *battle;
        std::vector<int> *scores;

    private:
        void render() const;
        void handleOnClick(sf::Vector2f mousePos) const;

    public:
        explicit Game(sf::RenderWindow *window, Core::Battle* battle);
        void run();
        void activate(std::string id);
        void addScene(Core::Scene *scene);
        void addScenes(std::vector<Core::Scene*> scenes);
    };
}
