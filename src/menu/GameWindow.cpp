//
// Created by CJ on 5/20/2025.
//

#include "GameWindow.h"

#include <iostream>

namespace UI
{

    GameWindow::GameWindow() : _camera(nullptr) {
        this->_window = sf::RenderWindow(sf::VideoMode({1280, 720}), "Window");
        this->_window.setFramerateLimit(30);
        this->_scene = new UI::Scene();
    }

    GameWindow::GameWindow(unsigned int width, unsigned int height, unsigned int fps, const std::string& title) : _camera(nullptr) {
        this->_window = sf::RenderWindow(sf::VideoMode({width, height}), title);
        this->_window.setFramerateLimit(fps);
        this->_scene = new UI::Scene();
    }

    GameWindow::GameWindow(unsigned int width, unsigned int height, unsigned int fps, const std::string& title, Scene &scene) : _camera(nullptr) {
        this->_window = sf::RenderWindow(sf::VideoMode({width, height}), title);
        this->_window.setFramerateLimit(fps);

        this->_scene = &scene;
    }

    bool GameWindow::setScene(Scene &scene) {
        this->_scene = &scene;
        return true;
    }

    void GameWindow::setCamera(Camera& camera) {
        this->_camera = &camera;
        this->_window.setView(*this->_camera->getView());
    }

    void GameWindow::drawScene() {

        std::unordered_map<unsigned int, std::vector<GameObject*>> objectMap = this->_scene->getObjectMap();
        std::unordered_map<unsigned int, std::vector<UIObject*>> uiObjectMap = this->_scene->getUIObjectMap();

        this->_window.clear(sf::Color::Black); // Clear window

        // Draw all game objects first
        for (int i = 0; i <= this->_scene->getHighestObjZ(); i++) {
            for (int j = 0; j < objectMap[i].size(); j++) { // Grab each game object and render them in Z order
                this->_window.draw(*objectMap[i][j]->getSprite());
            }
        }

        // Draw all UI objects above everything else
        for (int i = 0; i <= this->_scene->getHighestUIZ(); i++) {
            for (int j = 0; j < uiObjectMap[i].size(); j++) { // Grab each UI object and render them in Z order
                this->_window.draw(*uiObjectMap[i][j]->getSprite());
            }
        }

        this->_window.display();
    }

    void GameWindow::resize(const unsigned int x, const unsigned int y) {
        this->_window.setSize(sf::Vector2u(x, y));
    }

    void GameWindow::resize(const unsigned int x, const unsigned int y, unsigned int fps) {
        this->_window.setSize(sf::Vector2u(x, y));
        this->_window.setFramerateLimit(fps);
    }

    void GameWindow::update() {

        const sf::Vector2i mousePos = sf::Mouse::getPosition(this->_window);
        const bool currMouseState = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

        const std::vector<Button*> buttons = this->_scene->getButtons();

        while (const std::optional event = this->_window.pollEvent()) { // Grab event object
            if (event->is<sf::Event::Closed>()) this->_window.close(); // If they pressed X, signal for close
            else if (event->is<sf::Event::Resized>())
            {
            }
        }

        // Loop through all buttons, check if hovering and clicking
        for (int i = 0; i < buttons.size(); i++) {
            if (buttons[i]->isHovered(mousePos.x, mousePos.y)) {

                if (this->_prevHoverState == false) { // If we were not hovering last frame, call the hover function
                    buttons[i]->onHover();
                    this->_prevHoverState = true;
                }

                if (currMouseState == true && currMouseState != this->_prevMouseState) { // IF mouse is down AND it wasn't down last frame
                    buttons[i]->onPress();
                } else if (currMouseState == false && currMouseState != this->_prevMouseState) {
                    buttons[i]->onRelease();
                }
            }
            else if (this->_prevHoverState == true) { // If they're done hovering, call unhover function
                buttons[i]->offHover();
                this->_prevHoverState = false;
            }
        }

        if (currMouseState != this->_prevMouseState) {
            this->_prevMouseState = currMouseState;
        }
    }

    void GameWindow::close() {
        this->_window.close();
    }

    bool GameWindow::isOpen() const {
        return _window.isOpen();
    }

    Camera *GameWindow::getCamera() const {
        return this->_camera;
    }
}
