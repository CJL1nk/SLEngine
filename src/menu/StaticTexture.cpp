//
// Created by CJ on 5/20/2025.
//

#include "StaticTexture.h"

namespace UI {

Position StaticTexture::getPos() const {
    return this->_pos;
}

const sf::Sprite* StaticTexture::getSprite() const {
    return this->_sprite;
}

}