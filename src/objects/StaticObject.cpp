//
// Created by CJ on 5/20/2025.
//

#include "StaticObject.h"
#define ts this // ts pointer 💀

StaticObject::StaticObject() : _hitbox(nullptr), _sprite(nullptr), _pos(Position(0.0f, 0.0f, 0.0f)) {
    const sf::Texture texture = sf::Texture(sf::Vector2u{0,0});
    this->_sprite = new sf::Sprite(texture);
    const sf::FloatRect bounds = this->_sprite->getLocalBounds();
    this->_sprite->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f}); // Set center of object to center of sprite, NOT corner
};

StaticObject::StaticObject(const Position pos) : _hitbox(nullptr), _sprite(nullptr), _pos(pos) {
    const sf::Texture texture = sf::Texture(sf::Vector2u{0,0});
    this->_sprite = new sf::Sprite(texture);
    this->_sprite->setPosition({this->_pos.x, this->_pos.y});
    const sf::FloatRect bounds = this->_sprite->getLocalBounds();
    this->_sprite->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f}); // Set center of object to center of sprite, NOT corner
};

StaticObject::StaticObject(const Position pos, sf::Sprite& sprite) : _hitbox(nullptr), _sprite(&sprite), _pos(pos) {
    this->_sprite->setPosition({this->_pos.x, this->_pos.y});
    const sf::FloatRect bounds = this->_sprite->getLocalBounds();
    this->_sprite->setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f}); // Set center of object to center of sprite, NOT corner
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

    this->_sprite->setRotation(sf::degrees(this->_pos.rotation));
}

bool StaticObject::collidesWith(const GameObject &other) const {

    if (this->getHitbox()->getPos().x < other.getHitbox()->getPos().x + other.getHitbox()->getWidth() &&
    ts->getHitbox()->getPos().x + this->getHitbox()->getWidth() > other.getHitbox()->getPos().x &&
    this->getHitbox()->getPos().y < other.getHitbox()->getPos().y + other.getHitbox()->getHeight() &&
    this->getHitbox()->getPos().y + this->getHitbox()->getHeight() > other.getHitbox()->getPos().y) {
        return true;
    }
    return false;
}


Position StaticObject::getPos() const {
    return this->_pos;
}

const Position* StaticObject::getPosPtr() const {
    return &this->_pos;
}

Hitbox* StaticObject::getHitbox() const {
    return this->_hitbox;
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

    this->_sprite->setRotation(sf::degrees(this->_pos.rotation));
}

void StaticObject::setScale(float xScale, float yScale) {

    this->_sprite->setScale({xScale, yScale});
    if (this->_hitbox != nullptr) {
        this->_hitbox->setWidth(this->_hitbox->getWidth() * xScale);
        this->_hitbox->setHeight(this->_hitbox->getHeight() * yScale);
    }
}


