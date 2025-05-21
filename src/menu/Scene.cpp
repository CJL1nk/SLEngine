//
// Created by CJ on 5/20/2025.
//

#include "Scene.h"

namespace UI {

    Scene::Scene() {
        this->_sender = this;
    }

    bool Scene::addObject(GameObject& object) {

        if (!objectExists(object)) { // Only allow adding of an object once
            this->_objects.push_back(&object);

            // Set highest Z order
            if (object.getPos().zOrder > this->_highestObjZ) {
                this->_highestObjZ = object.getPos().zOrder;
            }

            _objectMap[object.getPos().zOrder].push_back(&object); // Add to map

            return true;
        }

        return false;
    }

    bool Scene::addUIObject(UIObject& uiObject) {

        if (!uiObjectExists(uiObject)) { // Only allow adding of a UI object once
            this->_uiObjects.push_back(&uiObject);

            // Set highest Z order
            if (uiObject.getPos().zOrder > this->_highestUIZ) {
                this->_highestUIZ = uiObject.getPos().zOrder;
            }

            _uiObjectMap[uiObject.getPos().zOrder].push_back(&uiObject); // Add to map

            return true;
        }

        return false;
    }

    bool Scene::removeObject(const GameObject& object) {

        bool found = objectExists(object);

        if (found) {
            // Remove from all objects
            this->_objects.erase(std::remove(this->_objects.begin(), this->_objects.end(), &object));
            // Remove from all object map
            this->_objectMap[object.getPos().zOrder].erase(std::remove(this->_objectMap[object.getPos().zOrder].begin(), this->_objectMap[object.getPos().zOrder].end(), &object)); // Holy line of code
        }

        return found;
    }

    bool Scene::removeUIObject(const UIObject& uiObject) {

        bool found = uiObjectExists(uiObject);

        if (found) {
            // Remove from all UI objects
            this->_uiObjects.erase(std::remove(this->_uiObjects.begin(), this->_uiObjects.end(), &uiObject));
            // Remove from UI object map
            this->_uiObjectMap[uiObject.getPos().zOrder].erase(std::remove(this->_uiObjectMap[uiObject.getPos().zOrder].begin(), this->_uiObjectMap[uiObject.getPos().zOrder].end(), &uiObject)); // Holy line of code
        }

        return found;
    }

    bool Scene::objectExists(const GameObject &object) const {

        // Get vector from map at given objects Z order, likely leading to fewer objects needing to be looped over
        for (int i = 0; i < this->_objectMap.at(object.getPos().zOrder).size(); i++) {
            if (this->_objectMap.at(object.getPos().zOrder)[i] == &object) {
                return true;
            }
        }

        return false;
    }

    bool Scene::uiObjectExists(const UIObject &uiObject) const {

        // Get vector from map at given objects Z order, likely leading to fewer objects needing to be looped over
        for (int i = 0; i < this->_uiObjectMap.at(uiObject.getPos().zOrder).size(); i++) {
            if (this->_uiObjectMap.at(uiObject.getPos().zOrder)[i] == &uiObject) {
                return true;
            }
        }

        return false;
    }

    std::vector<GameObject*> Scene::getObjects() const {
        return this->_objects;
    }

    unsigned int Scene::getHighestObjZ() const {
        return this->_highestObjZ;
    }

    unsigned int Scene::getHighestUIZ() const {
        return this->_highestUIZ;
    }

    std::unordered_map<unsigned int, std::vector<GameObject*>> Scene::getObjectMap() const {
        return this->_objectMap;
    };

    std::unordered_map<unsigned int, std::vector<UIObject*>> Scene::getUIObjectMap() const {
        return this->_uiObjectMap;
    };

}