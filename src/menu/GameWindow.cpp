//
// Created by CJ on 5/20/2025.
//

#include "GameWindow.h"

#include <iostream>

namespace UI
{

    GameWindow::GameWindow() {
        this->_window = sf::RenderWindow(sf::VideoMode({1280, 720}), "Window");
        this->_window.setFramerateLimit(60);
        this->_scene = new UI::Scene();
    }

    GameWindow::GameWindow(unsigned int width, unsigned int height, unsigned int fps, const std::string& title) {
        this->_window = sf::RenderWindow(sf::VideoMode({width, height}), title);
        this->_window.setFramerateLimit(fps);
        this->_scene = new UI::Scene();
    }

    GameWindow::GameWindow(unsigned int width, unsigned int height, unsigned int fps, const std::string& title, Scene &scene) {
        this->_window = sf::RenderWindow(sf::VideoMode({width, height}), title);
        this->_window.setFramerateLimit(fps);

        this->_scene = &scene;
    }

    bool GameWindow::setScene(Scene &scene) {
        this->_scene = &scene;
        return true;
    }

    void GameWindow::drawScene() {

        std::unordered_map<unsigned int, std::vector<GameObject*>> objectMap = this->_scene->getObjectMap();
        std::unordered_map<unsigned int, std::vector<GameObject*>> uiObjectMap = this->_scene->getUIObjectMap();

        this->_window.clear(sf::Color::Black);

        // Draw all game objects first
        for (int i = 0; i <= this->_scene->getHighestObjZ(); i++) {
            for (int j = 0; j < objectMap[i].size(); j++) {
                this->_window.draw(*objectMap[i][j]->getSprite());
            }
        }

        // Draw all UI objects above everything else
        for (int i = 0; i <= this->_scene->getHighestUIZ(); i++) {
            for (int j = 0; j < uiObjectMap[i].size(); j++) {
                this->_window.draw(*uiObjectMap[i][j]->getSprite());
            }
        }

        this->_window.display();
    }

    void GameWindow::pollEvents() {

        while (const std::optional event = this->_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) this->_window.close();
        }
    }

    void GameWindow::close() {
        this->_window.close();
    }

    bool GameWindow::isOpen() const {
        return _window.isOpen();
    }

}
