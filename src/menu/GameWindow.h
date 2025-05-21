//
// Created by CJ on 5/20/2025.
//

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "../includes.h"
#include "Scene.h"

namespace UI {

    /**
    * The GameWindow is the main window of your game. It's in charge of switching between scenes and can dynamicall resize at will
    */
    class GameWindow {

        public:
            GameWindow();
            GameWindow(unsigned int width, unsigned int height, unsigned int fps, const std::string& title);
            GameWindow(unsigned int width, unsigned int height, unsigned int fps, const std::string& title, Scene &scene);

            bool setScene(Scene& scene);
            void drawScene();

            void pollEvents();

            void close();

            bool isOpen() const;

        private:
            Scene* _scene;
            sf::RenderWindow _window;
    };

}

#endif //GAMEWINDOW_H
