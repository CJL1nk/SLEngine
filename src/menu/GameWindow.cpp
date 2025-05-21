//
// Created by CJ on 5/20/2025.
//

#include "GameWindow.h"

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
        this->_window.clear(sf::Color::Black);
        for (const GameObject* obj : this->_scene->getObjects()) {
            this->_window.draw(*obj->getSprite());
        }
    }


    bool GameWindow::isOpen() const {
        return _window.isOpen();
    }

}