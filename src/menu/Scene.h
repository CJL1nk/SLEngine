//
// Created by CJ on 5/20/2025.
//

#ifndef SCENE_H
#define SCENE_H

#include "../includes.h"

namespace UI {

	/**
	* The Scene class forms a screen based on given objects, buttons, and other UI elements.
	* Each scene can transition from one to another and has the ability to transition back to its "sender" scene
	*/
	class Scene {

		public:
            Scene();

            void Transition(Scene* nextScene);

    	private:
			Scene* sender;
            Position pos;
	};
}
#endif //SCENE_H
