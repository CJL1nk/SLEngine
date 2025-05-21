//
// Created by CJ on 5/20/2025.
//

#ifndef SCENE_H
#define SCENE_H

#include "../includes.h"
#include "../objects/GameObject.h"
#include "UIObject.h"

namespace UI {

	/**
	* The Scene class forms a screen based on given objects, buttons, and other UI elements.
	* Each scene knows its "sender" scene
	*/
	class Scene {

		public:
            Scene();

			bool addObject(GameObject& object);
			bool addUIObject(UIObject& uiObject);

            void transition(Scene* nextScene);

			std::vector<GameObject*> getObjects() const;
			std::unordered_map<unsigned int, std::vector<GameObject*>> getObjectMap() const;
			std::unordered_map<unsigned int, std::vector<GameObject*>> getUIObjectMap() const;
		    unsigned int getHighestObjZ() const;
		    unsigned int getHighestUIZ() const;

    	private:
			Scene* _sender;
		    unsigned int _highestObjZ = 0;
		    unsigned int _highestUIZ = 0;

			std::vector<GameObject*> _objects;
			std::vector<UIObject*> _uiObjects;

			std::unordered_map<unsigned int, std::vector<GameObject*>> _objectMap;
			std::unordered_map<unsigned int, std::vector<UIObject*>> _uiObjectMap;
	};
}
#endif //SCENE_H
