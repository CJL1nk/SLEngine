//
// Created by CJ on 5/20/2025.
//

#include "Hitbox.h"

Hitbox::Hitbox(GameObject* object, const float width, const float height) : _width(width), _height(height), _obj(object) {
    this->_pos = object->getPosPtr();
}

Position Hitbox::getPos() const {
    Position objPos = *_pos;

    objPos.x -= _width / 2.0f;
    objPos.y -= _height / 2.0f;

    return objPos; // Return new position object with offset to account for objects center
}

float Hitbox::getWidth() const {
    return this->_width;
}

float Hitbox::getHeight() const {
    return this->_height;
}

void Hitbox::setWidth(const float width) {
    this->_width = width;
}

void Hitbox::setHeight(const float height) {
    this->_height = height;
}