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
			StaticTexture();
			StaticTexture(sf::Texture& texture): _texture(texture) {};

	    private:
	        sf::Texture _texture;
            Position pos;
	};
}

#endif //STATICTEXTURE_H
