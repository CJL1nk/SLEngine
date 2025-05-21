//
// Created by CJ on 5/20/2025.
//

#include "../includes.h"
#include "UIObject.h"

#ifndef STATICTEXTURE_H
#define STATICTEXTURE_H

namespace UI {

	/**
	* The StaticTexture class allows some static texture object to be placed anywhere on the screen
	*/
	class StaticTexture : public UIObject {

		public:
			/**
			 * Default constructor, instantiates a new static texture on screen
			 * @param pos Position of object
			 * @param sprite Sprite of object
			 */
			StaticTexture(const Position pos, sf::Sprite& sprite) : _sprite(&sprite), _pos(pos) {
				_sprite->setPosition({_pos.x, _pos.y});
			};

			/**
			 * Returns the position of referenced object
			 * @return Position of referenced object
			 */
			[[nodiscard]] Position getPos() const override;
			/**
			 * Returns the sprite of referenced object
			 * @return Sprite of referenced object
			 */
			[[nodiscard]] const sf::Sprite* getSprite() const override;

	    private:
	        sf::Sprite* _sprite;;
            Position _pos;
	};
}

#endif //STATICTEXTURE_H
