//
// Created by CJ on 5/20/2025.
//

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "../includes.h"
#include "Scene.h"
#include "Camera.h"

namespace UI {

    /**
    * The GameWindow is the main window of your game. It's in charge of switching between scenes and can dynamically resize at will
    */
    class GameWindow {

        public:
            /**
             * Default constructor, initializes a 1280x720 30fps game window with an empty scene
             */
            GameWindow();

            /**
             * Constructor method, takes in a width, height, fps, and window title
             * @param width Width of window
             * @param height Height of window
             * @param fps Framerate to run at
             * @param title Title of window
             */
            GameWindow(unsigned int width, unsigned int height, unsigned int fps, const std::string& title);
            /**
             * Constructor method, takes in a width, height, fps, window title, and starting scene
             * @param width Width of window
             * @param height Height of window
             * @param fps Framerate to run at
             * @param title Title of window
             * @param scene Starting scene
             */
            GameWindow(unsigned int width, unsigned int height, unsigned int fps, const std::string& title, Scene &scene);

            /**
             * Transitions to a different scene
             * @param scene Scene to transition to
             * @return True if successful, false otherwise
             */
            bool setScene(Scene& scene);
            /**
             * Sets the camera for referenced GameWindow object
             * @param camera Camera to set
             */
            void setCamera(Camera& camera);

            /**
             * Draws all elements of current scene in window
             */
            void drawScene();
            /**
             * Resizes the game window
             * @param x Width to resize to
             * @param y Height to resize to
             */
            void resize(unsigned int x, unsigned int y);
            /**
             * Resizes the game window and sets FPS
             * @param x Width to resize to
             * @param y Height to resize to
             * @param fps FPS to set to
             */
            void resize(unsigned int x, unsigned int y, unsigned int fps);
            /**
             * Polls and updates all events in window, PLEASE CALL THIS FIRST IN MAIN LOOP!!!
             */
            void update();
            /**
             * Closes the game window
             */
            void close();
            /**
             * Determines whether window is open
             * @return True if window is open
             */
            bool isOpen() const;

            /**
             * Returns a pointer to the camera of referenced window
             * @return Pointer to the camera of referenced window
             */
            Camera* getCamera() const;

        private:
            Scene* _scene;
            sf::RenderWindow _window;
            Camera* _camera;

            bool _prevMouseState = false;
            bool _prevHoverState = false;
    };

}

#endif //GAMEWINDOW_H
