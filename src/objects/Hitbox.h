//
// Created by CJ on 5/20/2025.
//

#ifndef HITBOX_H
#define HITBOX_H

#include "../includes.h"
#include "GameObject.h"

class Hitbox {

    public:
        Hitbox(GameObject* object, float width, float height) : _obj(object), _width(width), _height(height) {
            this->_pos = object->getPosPtr();
        };

        Position getPos() {
            return *this->_pos;
        }

        float getWidth() {
            return this->_width;
        }

        float getHeight() {
            return this->_height;
        }

    private:
        float _width, _height;
        const Position* _pos; // Position is a POINTER so it moves with its attached object
        GameObject* _obj;
};

#endif //HITBOX_H
