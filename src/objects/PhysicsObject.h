//
// Created by CJ on 5/20/2025.
//

#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include "GameObject.h"
#include "Hitbox.h"

/**
 * The StaticObject class represents some game object with physics that can move on its own
 */
class PhysicsObject : public GameObject {

    public:
        PhysicsObject();

        bool initHitbox(const Hitbox& hitbox);

        [[nodiscard]] Position getPos() const override;
        [[nodiscard]] const Position* getPosPtr() const override;

        [[nodiscard]] Hitbox getHitbox() const;

    private:
        const Hitbox* _hitbox;

        float _vx, _vy; // X and Y velocity
        float _ax, _ay; // X and Y acceleration;
        Position _pos;
};



#endif //PHYSICSOBJECT_H
