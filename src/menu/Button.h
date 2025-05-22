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
			Button(const Position pos, sf::Sprite& sprite, Func&& f, Args&&... args) : _function(f), _pos(pos), _sprite(&sprite) {
				_sprite->setPosition({_pos.x, _pos.y});
			};

			template <typename Func, typename... Args>
			void setPress(Func&& f, Args&&... args) {
				// Store a lambda that captures the function and its arguments
				this->_function = std::bind(std::forward<Func>(f), std::forward<Args>(args)...);
			}
			template <typename Func, typename... Args>
			void setOnHover(Func&& f, Args&&... args) {
				// Store a lambda that captures the function and its arguments
				this->_onHoverFunc = std::bind(std::forward<Func>(f), std::forward<Args>(args)...);
			}
			template <typename Func, typename... Args>
			void setOffHover(Func&& f, Args&&... args) {
				// Store a lambda that captures the function and its arguments
				this->_offHoverFunc = std::bind(std::forward<Func>(f), std::forward<Args>(args)...);
			}

	        void press() const;
            void onHover();
            void offHover();

		    [[nodiscard]] bool isHovered(float x, float y) const;

		    [[nodiscard]] Position getPos() const override;
			[[nodiscard]] const sf::Sprite* getSprite() const override;

	    private:
			std::function<void()> _function;
			std::function<void()> _onHoverFunc;
			std::function<void()> _offHoverFunc;

			Position _pos;
		    sf::Sprite* _sprite;
		};
}

#endif //BUTTON_H
