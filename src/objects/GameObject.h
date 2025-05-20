//
// Created by CJ on 5/20/2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../includes.h"

/**
* The GameObject class is a parent class for various object-type classes
* Its sole purpose is to allow the generalizing of game objects and cannot be instantiated alone
*/
class GameObject {

    public:
        [[nodiscard]] virtual Position getPos() const = 0;
        [[nodiscard]] virtual const Position* getPosPtr() const = 0; // For use by hitbox class or any other attached object
};



#endif //GAMEOBJECT_H
