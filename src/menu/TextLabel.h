//
// Created by CJ on 5/20/2025.
//

#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include "../includes.h"
#include "UIObject.h"

namespace UI {

	/**
	* The TextLabel class allows the user to create a text label of any given font and put it somewhere on screen
	*/
	class TextLabel : public UIObject {
		public:
            TextLabel();
        private:
			sf::Text text;
            sf::Font font;
            Position pos;
	};
}

#endif //TEXTLABEL_H
