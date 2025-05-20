//
// Created by CJ on 5/20/2025.
//

#include "PhysicsObject.h"

bool PhysicsObject::initHitbox(const Hitbox& hitbox) {
    this->_hitbox = &hitbox;

    return true;
}

Position PhysicsObject::getPos() const {
    return this->_pos;
}

const Position* PhysicsObject::getPosPtr() const {
    return &this->_pos;
}

Hitbox PhysicsObject::getHitbox() const {
    return *this->_hitbox;
};