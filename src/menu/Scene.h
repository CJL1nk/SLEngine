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
	* Each scene knows its "sender" scene
	*/
	class Scene {

		public:
            Scene();

			bool addObject(GameObject& object);

            void transition(Scene* nextScene);

			std::vector<GameObject*> getObjects() const;
			std::unordered_map<unsigned int, std::vector<GameObject*>> getObjectMap() const;
		    unsigned int getHighestZ() const;

    	private:
			Scene* _sender;
		    unsigned int _highestZ = 0;

			std::vector<GameObject*> _objects;
			std::unordered_map<unsigned int, std::vector<GameObject*>> _objectMap;
	};
}
#endif //SCENE_H
