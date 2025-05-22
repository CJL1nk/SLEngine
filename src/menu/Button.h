//
// Created by CJ on 5/20/2025.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "../includes.h"
#include "UIObject.h"

namespace UI {

	/**
	* The Button class creates a clickable button with the ability to call some user specified function
	*/
	class Button : public UIObject {

		public:
			Button();
			Button(Position pos, sf::Sprite& sprite);
			template <typename Func, typename... Args>
			Button(Position pos, sf::Sprite& sprite, Func&& f, Args&&... args);

			template <typename Func, typename... Args>
			void setPress(Func&& f, Args&&... args);

	        void press();

            void onHover();

	    private:
			std::function<void()> _function;
			Position _pos;
		};
}

#endif //BUTTON_H
