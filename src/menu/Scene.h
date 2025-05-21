//
// Created by CJ on 5/20/2025.
//

#ifndef SCENE_H
#define SCENE_H

#include "../includes.h"
#include "../objects/GameObject.h"

namespace UI {

	/**
	* The Scene class forms a screen based on given objects, buttons, and other UI elements.
	* Each scene can transition from one to another and has the ability to transition back to its "sender" scene
	*/
	class Scene {

		public:
            Scene();

			bool addObject(GameObject& object);

            void transition(Scene* nextScene);

			std::vector<GameObject*> getObjects();

    	private:
			Scene* _sender;

			std::vector<GameObject*> _objects;
	};
}
#endif //SCENE_H
