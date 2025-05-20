//
// Created by CJ on 5/20/2025.
//

#include "Entity.h"


Position Entity::getPos() const {
    return this->_pos;
}

const Position* Entity::getPosPtr() const {
    return &this->_pos;
}