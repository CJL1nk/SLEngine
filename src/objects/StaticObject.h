//
// Created by CJ on 5/20/2025.
//

#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "GameObject.h"
#include "Hitbox.h"

class StaticObject : public GameObject{

    public:
        StaticObject() : _hitbox(nullptr), _sprite(nullptr), _pos(Position(0.0f, 0.0f, 0.0f)) {
            const sf::Texture texture = sf::Texture(sf::Vector2u{0,0});
            _sprite = new sf::Sprite(texture);
        };
        explicit StaticObject(const Position pos) : _hitbox(nullptr), _sprite(nullptr), _pos(pos) {
            const sf::Texture texture = sf::Texture(sf::Vector2u{0,0});
            _sprite = new sf::Sprite(texture);
        };
        StaticObject(const Position pos, const sf::Sprite& sprite) : _hitbox(nullptr), _sprite(&sprite), _pos(pos) {};

        bool initHitbox();
        bool initHitbox(const Hitbox& hitbox);

        [[nodiscard]] Position getPos() const override;

        [[nodiscard]] const Position* getPosPtr() const override;

        [[nodiscard]] Hitbox getHitbox() const;

    private:
        const Hitbox* _hitbox;
        const sf::Sprite *_sprite;
        Position _pos;
};



#endif //STATICOBJECT_H
