//
// Created by CJ on 5/20/2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../includes.h"

/**
* The GameObject class is a wrapper class for various object-type classes
* Its sole purpose is to allow the generalizing of game objects and cannot be instantiated alone
*/
class GameObject {

    public:
        virtual ~GameObject() = default;

        /**
         * Returns the position of referenced object
         * @return Position of referenced object
         */
        [[nodiscard]] virtual Position getPos() const = 0;
        /**
         * Returns a pointer to the position  of referenced object
         * @return Pointer to the position  of referenced object
         */
        [[nodiscard]] virtual const Position* getPosPtr() const = 0; // For use by hitbox class or any other attached object
        /**
         * Returns a pointer to the sprite of referenced object
         * @return Pointer to the sprite of referenced object
         */
        [[nodiscard]] virtual const sf::Sprite* getSprite() const = 0;
};



#endif //GAMEOBJECT_H
