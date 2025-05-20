//
// Created by CJ on 5/20/2025.
//

#include "StaticObject.h"

bool StaticObject::initHitbox() {

    if (this-> _hitbox != nullptr) {
        return false;
    }

    this->_hitbox = new Hitbox(this, this->_sprite->getLocalBounds().size.x, this->_sprite->getLocalBounds().size.y);
    return true;
}

bool StaticObject::initHitbox(const Hitbox& hitbox) {

    if (this-> _hitbox != nullptr) {
        return false;
    }

    this->_hitbox = &hitbox;
    return true;
}

[[nodiscard]] Position StaticObject::getPos() const {
    return this->_pos;
}

[[nodiscard]] const Position* StaticObject::getPosPtr() const {
    return &this->_pos;
}

Hitbox StaticObject::getHitbox() const {
    return *this->_hitbox;
};