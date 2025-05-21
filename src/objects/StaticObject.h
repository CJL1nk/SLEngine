//
// Created by CJ on 5/20/2025.
//

#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "GameObject.h"
#include "Hitbox.h"

/**
 * The StaticObject class represents some static game object that cannot be moved unless specifically done so by the user
 */
class StaticObject : public GameObject{

    public:
        /**
         * Default constructor, initializes an empty static object at position 0, 0, 0 with an empty texture and sprite
         */
        StaticObject();
        /**
         * Constructor, initializes a static object at a given position with no sprite
         * @param pos Position to set object at
         */
        explicit StaticObject(Position pos);
        /**
         * Constructor, initializes a static object with a given position and sprite
         * @param pos Position to set object at
         * @param sprite Sprite for object to use
         */
        StaticObject(Position pos, sf::Sprite& sprite);

        /**
         * Initializes a default hitbox attached to referenced object
         * Width and height are equal to the attached object's sprite's width and height
         * @return True if successful, false otherwise
         */
        bool initHitbox();
        /**
         * Initializes a hitbox attached to referenced object
         * @param width Width of hitbox
         * @param height Height of hitbox
         * @return True if successful, false otherwise
         */
        bool initHitbox(float width, float height);

        /**
         * Moves an object by a specified amount
         * Adds given values to referenced object's x and y coordinates
         * @param x X distance to move
         * @param y Y distance to move
         */
        void move(float x, float y);
        /**
         * Moves an object by a specified amount
         * Adds given values to referenced object's x, y, and rotation. !!! Z ORDER UNCHANGED !!!
         * @param pos Positional values to add
         */
        void move(Position pos);
        /**
         * Adds a given number of degrees to an objects rotation
         * @param degrees Degrees to add
         */
        void rotate(float degrees);

        /**
         * Returns the position of referenced object
         * @return Position of referenced object
         */
        [[nodiscard]] Position getPos() const override;
        /**
         * Returns a pointer to the position of referenced object
         * @return Pointer to the position of referenced object
         */
        [[nodiscard]] const Position* getPosPtr() const override;
        /**
         * Returns the hitbox of referenced object
         * @return Hitbox of referenced object
         */
        [[nodiscard]] Hitbox getHitbox() const;
        /**
         * Returns a pointer to the sprite of referenced object
         * @return pPointer to the sprite of referenced object
         */
        [[nodiscard]] const sf::Sprite* getSprite() const override;

        /**
         * Sets the position of referenced object
         * @param pos Position to set
         */
        void setPos(const Position& pos);

        /**
         * Sets the rotation of referenced object
         * @param degrees Rotation degrees to set
         */
        void setRotation(float degrees);

    private:
        const Hitbox* _hitbox;
        sf::Sprite* _sprite;
        Position _pos;
};



#endif //STATICOBJECT_H
