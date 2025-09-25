//
// Created by CJ on 5/20/2025.
//

#include "Button.h"

#include <iostream>

namespace UI {

    Button::Button(const Position pos, sf::Sprite& sprite) : _onPressFunc(nullptr), _onReleaseFunc(nullptr), _onHoverFunc(nullptr), _offHoverFunc(nullptr), _pos(pos), _sprite(&sprite) {
        this->_sprite->setPosition({this->_pos.x, this->_pos.y});
        const sf::FloatRect bounds = this->_sprite->getLocalBounds();
        this->_sprite->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f}); // Set center of object to center of sprite, NOT corner
    }

    void Button::setOnPress(const std::function<void()>& func) {
        this->_onPressFunc = func;
    }
    void Button::setOnRelease(const std::function<void()>& func) {
        this->_onReleaseFunc = func;
    }
    void Button::setOnHover(const std::function<void()>& func) {
        this->_onHoverFunc = func;
    }
    void Button::setOffHover(const std::function<void()>& func) {
        this->_offHoverFunc = func;
    }

    void Button::setPos(Position &pos) {
        this->_pos = pos;
        this->_sprite->setPosition(sf::Vector2f(this->_pos.x, this->_pos.y));
    }

    void Button::onPress() const {
        if (this->_onPressFunc) { // If they've added a function, call it
            this->_onPressFunc();
        }
    }

    void Button::onRelease() const {
        if (this->_onReleaseFunc) { // If they've added a function, call it
            this->_onReleaseFunc();
        }
    }

    void Button::onHover() const {
        if (this->_onHoverFunc) { // If they've added a function, call it
            this->_onHoverFunc();
        }
    }

    void Button::offHover() const {
        if (this->_offHoverFunc) { // If they've added a function, call it
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
