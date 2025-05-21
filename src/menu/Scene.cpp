//
// Created by CJ on 5/20/2025.
//

#include "Scene.h"

namespace UI {

    Scene::Scene() {
        this->_sender = this;
    }

    bool Scene::addObject(GameObject& object) {
        this->_objects.push_back(&object);

        // Set highest Z order
        if (object.getPos().zOrder > this->_highestObjZ) {
            this->_highestObjZ = object.getPos().zOrder;
        }

        _objectMap[object.getPos().zOrder].push_back(&object); // Add to map

        return true;
    }

    bool Scene::addUIObject(UIObject& uiObject) {
        this->_uiObjects.push_back(&uiObject);

        // Set highest Z order
        if (uiObject.getPos().zOrder > this->_highestUIZ) {
            this->_highestUIZ = uiObject.getPos().zOrder;
        }

        _uiObjectMap[uiObject.getPos().zOrder].push_back(&uiObject); // Add to map

        return true;
    }

    bool Scene::removeObject(const GameObject& object) {

        bool objectExists = false;

        // Remove from all objects
        for (int i = 0; i < this->_objects.size(); i++) {
            if (this->_objects[i] == &object) {
                objectExists = true;
                this->_objects.erase(std::remove(this->_objects.begin(), this->_objects.end(), &object));
            }
        }

        // Remove from Z order map
        if (objectExists) {
            for (int i = 0; i < this->_objectMap[object.getPos().zOrder].size(); i++) {
                if (this->_objectMap[object.getPos().zOrder][i] == &object) {
                    this->_objectMap[object.getPos().zOrder].erase(std::remove(this->_objects.begin(), this->_objects.end(), &object));
                }
            }
        }

        return objectExists;
    }

    bool Scene::removeUIObject(const UIObject& uiObject) {

        bool objectExists = false;

        // Remove from all objects
        for (int i = 0; i < this->_uiObjects.size(); i++) {
            if (this->_uiObjects[i] == &uiObject) {
                objectExists = true;
                this->_uiObjects.erase(std::remove(this->_uiObjects.begin(), this->_uiObjects.end(), &uiObject));
            }
        }

        // Remove from Z order map
        if (objectExists) {
            for (int i = 0; i < this->_uiObjectMap[uiObject.getPos().zOrder].size(); i++) {
                if (this->_uiObjectMap[uiObject.getPos().zOrder][i] == &uiObject) {
                    this->_uiObjectMap[uiObject.getPos().zOrder].erase(std::remove(this->_uiObjects.begin(), this->_uiObjects.end(), &uiObject));
                }
            }
        }

        return objectExists;
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