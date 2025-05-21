//
// Created by CJ on 5/20/2025.
//

#ifndef UIOBJECT_H
#define UIOBJECT_H

#include "../includes.h"

namespace UI {

    class UIObject {

        public:
            [[nodiscard]] virtual Position getPos() const = 0;
            [[nodiscard]] virtual const sf::Sprite* getSprite() const = 0;
    };

}

#endif //UIOBJECT_H
