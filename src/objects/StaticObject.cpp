//
// Created by CJ on 5/20/2025.
//

#include "StaticObject.h"

StaticObject::StaticObject() : _hitbox(nullptr), _sprite(nullptr), _pos(Position(0.0f, 0.0f, 0.0f)) {
    const sf::Texture texture = sf::Texture(sf::Vector2u{0,0});
    _sprite = new sf::Sprite(texture);
};

StaticObject::StaticObject(const Position pos) : _hitbox(nullptr), _sprite(nullptr), _pos(pos) {
    const sf::Texture texture = sf::Texture(sf::Vector2u{0,0});
    _sprite = new sf::Sprite(texture);
    _sprite->setPosition({_pos.x, _pos.y});
};

StaticObject::StaticObject(const Position pos, sf::Sprite& sprite) : _hitbox(nullptr), _sprite(&sprite), _pos(pos) {
    _sprite->setPosition({_pos.x, _pos.y});
};

bool StaticObject::initHitbox() {

    if (this-> _hitbox != nullptr) { // Don't allow changing hitbox of object, MAY change in future
        return false;
    }

    this->_hitbox = new Hitbox(this, this->_sprite->getLocalBounds().size.x, this->_sprite->getLocalBounds().size.y);
    return true;
}

bool StaticObject::initHitbox(const float width, const float height) {

    if (this-> _hitbox != nullptr) { // Don't allow changing hitbox of object, MAY change in future
        return false;
    }

    this->_hitbox = new Hitbox(this, width, height);
    return true;
}

void StaticObject::move(const float x, const float y) {
    this->_pos.x += x;
    this->_pos.y += y;

    this->_sprite->setPosition({this->_pos.x, this->_pos.y});
}

void StaticObject::move(const Position pos) {
    this->_pos.x += pos.x;
    this->_pos.y += pos.y;
    this->_pos.rotation += pos.rotation;

    this->_sprite->setPosition({this->_pos.x, this->_pos.y});
}

void StaticObject::rotate(const float degrees) {
    this->_pos.rotation += degrees;
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

void StaticObject::setPos(const Position &pos) {
    this->_pos = pos;

    this->_sprite->setPosition({this->_pos.x, this->_pos.y});
}

void StaticObject::setRotation(const float degrees) {
    this->_pos.rotation = degrees;
}

