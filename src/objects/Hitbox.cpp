//
// Created by CJ on 5/20/2025.
//

#include "Hitbox.h"

Hitbox::Hitbox(GameObject* object, const float width, const float height) : _width(width), _height(height), _obj(object) {
    this->_pos = object->getPosPtr();
}

Position Hitbox::getPos() const {
    return *this->_pos;
}

float Hitbox::getWidth() const {
    return this->_width;
}

float Hitbox::getHeight() const {
    return this->_height;
}