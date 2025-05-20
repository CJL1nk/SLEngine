//
// Created by CJ on 5/20/2025.
//

#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.h"
#include "Hitbox.h"

class Entity : public GameObject {

    public:
        Entity();
        bool initHitbox(Hitbox* hitbox);

        Position getPos() const;
        const Position* getPosPtr() const;

    private:
        Hitbox* _hitbox;

        Position _pos;
};



#endif //ENTITY_H
