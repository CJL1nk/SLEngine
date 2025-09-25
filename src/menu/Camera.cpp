//
// Created by CJ on 5/20/2025.
//

#include "Camera.h"

namespace UI {

    Camera::Camera() : _attachedObject(nullptr) {
        this->_view = new sf::View({0.0f, 0.0f}, {480.0f, 480.0f});
    };

    Camera::Camera(const float xPos, const float yPos) : _attachedObject(nullptr) {
        this->_view = new sf::View({xPos, yPos}, {480.0f, 480.0f});
    };

    Camera::Camera(const float xPos, const float yPos, const float width, const float height) : _attachedObject(nullptr) {
        this->_view = new sf::View({xPos, yPos}, {width, height});
    };

    Camera::Camera(Position pos) : _attachedObject(nullptr) {
        this->_view = new sf::View({pos.x, pos.y}, {480.0f, 480.0f});
        this->_view->setRotation(sf::degrees(pos.rotation));
    };

    Camera::Camera(Position pos, const float width, const float height) : _attachedObject(nullptr) {
        this->_view = new sf::View({pos.x, pos.y}, {width, width});
        this->_view->setRotation(sf::degrees(pos.rotation));
    };

    void Camera::move(Position pos) const {
        this->_view->move({pos.x, pos.y});
    }

    void Camera::move(const float x, const float y) const {
        this->_view->move({x, y});
    }

    void Camera::rotate(const float angle) const {
        this->_view->rotate(sf::degrees(angle));
    }

    bool Camera::attachObject(GameObject& obj) {
        this->_attachedObject = &obj;
        return true;
    }

    void Camera::setPos(Position pos) {
        this->_view->setCenter(sf::Vector2f(pos.x, pos.y));
    }

    void Camera::setPos(float x, float y) {
        this->_view->setCenter(sf::Vector2f(x, y));
    }


    bool Camera::hasAttachedObject() const {
        return this->_attachedObject != nullptr;
    }

    [[nodiscard]] sf::View* Camera::getView() const {
        return this->_view;
    }

    [[nodiscard]] GameObject* Camera::getAttachedObject() const {
        return this->_attachedObject;
    }

}