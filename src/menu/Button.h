//
// Created by CJ on 5/20/2025.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "../includes.h"
#include "UIObject.h"

namespace UI {

	/**
	* The Button class creates a clickable button with the ability to call some user specified function on presses and hovers.
	* Each button MUST have a position and sprite to display on screen. The button's hitbox will always be the same size as the sprite.
	*/
	class Button : public UIObject {

		public:
			/**
			 * Default constructor, initializes a button at a given position with a given sprite
			 * @param pos
			 * @param sprite
			 */
			Button(Position pos, sf::Sprite& sprite);

			/**
			 * Sets the function to call when the button is pressed
			 * @param func Function to call on press
			 */
			void setOnPress(const std::function<void()>& func);
			/**
			 * Sets the function to call when the button is released
			 * @param func Function to call on release
			 */
			void setOnRelease(const std::function<void()>& func);
			/**
			 * Sets the function to call when the button is hovered over
			 * @param func Function to call when the button is hovered over
			 */
			void setOnHover(const std::function<void()>& func);
			/**
			 * Sets the function to call when the button is no longer hovered over
			 * @param func Function to call when the button is no longer hovered over
			 */
			void setOffHover(const std::function<void()>& func);

			/**
			 * Sets the position of current UI object
			 * @param pos Position to set
			 */
			void setPos(Position &pos) override;

			/**
			 * Calls the function the user gave it to call on button press, if it exists
			 */
			void onPress() const;
			/**
			 * Calls the function the user gave it to call on button release, if it exists
			 */
	        void onRelease() const;
			/**
			 * Calls the function the user gave it to call on button hover, if it exists
			 */
            void onHover() const;
			/**
			 * Calls the function the user gave it to call off button hover, if it exists
			 */
            void offHover() const;

			/**
			 * Determines whether some given position "hovers" within the buttons bounds
			 * @param x X position
			 * @param y Y position
			 * @return True if it does hover, false otherwise
			 */
			[[nodiscard]] bool isHovered(float x, float y) const;

			/**
			 * Returns the position of referenced Button object
			 * @return Position of referenced Button object
			 */
			[[nodiscard]] Position getPos() const override;
			/**
			 * Returns a pointer to the sprite of referenced Button object
			 * @return Pointer to the sprite of referenced Button object
			 */
			[[nodiscard]] const sf::Sprite* getSprite() const override;

	    private:
			std::function<void()> _onPressFunc;
			std::function<void()> _onReleaseFunc;
			std::function<void()> _onHoverFunc;
			std::function<void()> _offHoverFunc;

			Position _pos;
		    sf::Sprite* _sprite;
		};
}

#endif //BUTTON_H
