//
// Created by CJ on 5/20/2025.
//

#ifndef UIOBJECT_H
#define UIOBJECT_H

#include "../includes.h"

namespace UI {
    /**
     * The UIObject class is a general wrapper class for various UI objects, allows for generalization during rendering
     */
    class UIObject {

        public:
            virtual ~UIObject() = default;

            /**
             * Returns the position of referenced object
             * @return Position of referenced object
             */
            [[nodiscard]] virtual Position getPos() const = 0;
            /**
             * Returns the sprite of referenced object
             * @return Sprite of referenced object
             */
            [[nodiscard]] virtual const sf::Sprite* getSprite() const = 0;
    };

}

#endif //UIOBJECT_H
