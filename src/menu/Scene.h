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
			/**
			 * Default constructor, instantiates an empty scene
			 */
			Scene();

			/**
			 * Adds some game object as an element to the scene
			 * @param object Game object to add
			 * @return True if successful, false otherwise
			 */
			bool addObject(GameObject& object);
			/**
			 * Adds some UI object as an element to the scene
			 * @param uiObject UI object to add
			 * @return True if successful, false otherwise
			 */
			bool addUIObject(UIObject& uiObject);

			/**
			 * Transitions the window from one scene to another
			 * @param nextScene Scene to transition to
			 */
			void transition(Scene* nextScene);

			/**
			 * Returns a vector containing pointers to all objects in referenced scene
			 * @return Vector containing pointers to every object in referenced scene
			 */
			std::vector<GameObject*> getObjects() const;
			/**
			 * Returns a map containing all Game Objects in referenced scene, where the KEY is the z order
			 * and the VALUE is a vector containing all objects with that z order
			 * @return Map containing all Game Objects in referenced scene
			 */
			std::unordered_map<unsigned int, std::vector<GameObject*>> getObjectMap() const;
			/**
			 * Returns a map containing all UI Objects in referenced scene, where the KEY is the z order
			 * and the VALUE is a vector containing all objects with that z order
			 * @return Map containing all UI Objects in referenced scene
			 */
			std::unordered_map<unsigned int, std::vector<UIObject*>> getUIObjectMap() const;

			/**
			 * Returns the highest Game object Z order used within referenced scene
			 * @return Highest Game object Z order used within referenced scene
			 */
			unsigned int getHighestObjZ() const;
			/**
			 * Returns the highest UI object Z order used within referenced scene
			 * @return Highest UI object Z order used within referenced scene
			 */
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
