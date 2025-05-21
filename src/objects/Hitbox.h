//
// Created by CJ on 5/20/2025.
//

#ifndef HITBOX_H
#define HITBOX_H

#include "../includes.h"
#include "GameObject.h"

class Hitbox {

    public:
        Hitbox(GameObject* object, const float width, const float height) : _width(width), _height(height), _obj(object) {
            this->_pos = object->getPosPtr();
        };

        [[nodiscard]] Position getPos() const {
            return *this->_pos;
        }

        [[nodiscard]] float getWidth() const {
            return this->_width;
        }

        [[nodiscard]] float getHeight() const {
            return this->_height;
        }

    private:
        float _width, _height;
        const Position* _pos; // Position is a POINTER so it moves with its attached object
        GameObject* _obj;
};

#endif //HITBOX_H
