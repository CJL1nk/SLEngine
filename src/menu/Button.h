//
// Created by CJ on 5/20/2025.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "../includes.h"

namespace UI {

	/**
	* The Button class creates a clickable button with the ability to call a user specififed function callback
	*/
	class Button {

	public:
		Button();

    private:
        void* callback;
		Position pos;
	};
}

#endif //BUTTON_H
