//
// Created by CJ on 5/20/2025.
//

#include "Button.h"

#include <iostream>

namespace UI {

    Button::Button() : _function(nullptr), _pos(Position()) {
        const sf::Texture texture = sf::Texture(sf::Vector2u{0,0});
        _sprite = new sf::Sprite(texture);
        _sprite->setPosition({_pos.x, _pos.y});
    }

    Button::Button(const Position pos, sf::Sprite& sprite) : _function(nullptr), _pos(pos), _sprite(&sprite) {
        _sprite->setPosition({_pos.x, _pos.y});
    }

    void Button::press() const {
        if (this->_function) { // If they've added a function, call it
            this->_function();
        }
    }

    void Button::onHover() {
        if (this->_onHoverFunc) {
            this->_onHoverFunc();
        }
    }

    void Button::offHover() {
        if (this->_offHoverFunc) {
            this->_offHoverFunc();
        }
    }


    bool Button::isHovered(const float x, const float y) const {

        sf::Vector2f point(x, y);

        if (this->_sprite->getGlobalBounds().contains(point)) {
            return true;
        }

        return false;
    }

    Position Button::getPos() const {
        return _pos;
    }

    const sf::Sprite* Button::getSprite() const {
        return _sprite;
    }


}
