//
// Created by CJ on 5/20/2025.
//

#ifndef CAMERA_H
#define CAMERA_H

#include "../includes.h"
#include "../objects/GameObject.h"

namespace UI {

    class Camera {

        public:

            Camera();
            Camera(float xPos, float yPos);;
            Camera(float xPos, float yPos, float width, float height);;
            explicit Camera(Position pos);
            Camera(Position , float width, float height);;

            void move(Position pos) const;
            void move(float x, float y) const;
            void rotate(float angle) const;
            bool attachObject(GameObject& obj);

            bool hasAttachedObject() const;

            void setPos(Position pos);
            void setPos(float x, float y);

            [[nodiscard]] sf::View* getView() const;
            [[nodiscard]] GameObject* getAttachedObject() const;

        private:
            sf::View* _view;
            GameObject* _attachedObject;
    };
}

#endif //CAMERA_H
