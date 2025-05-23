//
// Created by CJ on 5/20/2025.
//

#ifndef HITBOX_H
#define HITBOX_H

#include "../includes.h"
#include "GameObject.h"

class GameObject; // Forward declaration to avoid circular import linker screaming and crying stupid asshole

/**
 * The Hitbox class defines a hitbox, which is attached to any game object
 * Its position is a pointer to whichever object it's "attached" to so it maintains the same position
 */
class Hitbox {

    public:
        /**
         * Default constructor, takes an object to attach to, a hitbox width, and a hitbox height
         * @param object Object to attach to
         * @param width Hitbox width
         * @param height Hitbox height
         */
        Hitbox(GameObject* object, float width, float height);

        /**
         * Returns the position of referenced Hitbox object, WITH offset for center
         * @return Position of referenced Hitbox object
         */
        [[nodiscard]] Position getPos() const;
        /**
         * Returns width of referenced Hitbox object
         * @return Width of referenced Hitbox object
         */
        [[nodiscard]] float getWidth() const;
        /**
         * Returns height of referenced Hitbox object
         * @return Height of referenced Hitbox object
         */
        [[nodiscard]] float getHeight() const;

        /**
         * Sets the width of referenced hitbox
         * @param width Width to set
         */
        void setWidth(float width);
        /**
         * Sets the height of referenced hitbox
         * @param height Height to set
         */
        void setHeight(float height);


    private:
        float _width, _height;
        const Position* _pos; // Position is a POINTER so it moves with its attached object
        GameObject* _obj;
};

#endif //HITBOX_H
