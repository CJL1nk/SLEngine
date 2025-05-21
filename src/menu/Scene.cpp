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

        _objectMap[object.getPos().zOrder].push_back(&object);

        return true;
    }

    bool Scene::addUIObject(UIObject& uiObject) {
        this->_uiObjects.push_back(&uiObject);

        // Set highest Z order
        if (uiObject.getPos().zOrder > this->_highestUIZ) {
            this->_highestUIZ = uiObject.getPos().zOrder;
        }

        _uiObjectMap[uiObject.getPos().zOrder].push_back(&uiObject);

        return true;
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

    std::unordered_map<unsigned int, std::vector<GameObject*>> Scene::getUIObjectMap() const {
        return this->_objectMap;
    };

}