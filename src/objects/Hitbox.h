//
// Created by CJ on 5/20/2025.
//

#ifndef HITBOX_H
#define HITBOX_H

#include "../includes.h"
#include "GameObject.h"

class Hitbox {

    public:
        Hitbox();

    private:
        float width, height;
        Position* pos; // Position is a POINTER so it moves with its attached object
        GameObject* obj;
};

#endif //HITBOX_H
