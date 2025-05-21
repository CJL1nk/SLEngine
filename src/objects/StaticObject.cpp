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

Position StaticObject::getPos() const {
    return this->_pos;
}

const Position* StaticObject::getPosPtr() const {
    return &this->_pos;
}

Hitbox StaticObject::getHitbox() const {
    return *this->_hitbox;
};

const sf::Sprite* StaticObject::getSprite() const {
    return this->_sprite;
}

