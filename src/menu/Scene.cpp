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
        if (object.getPos().zOrder > this->_highestZ) {
            this->_highestZ = object.getPos().zOrder;
        }

        _objectMap[object.getPos().zOrder].push_back(&object);

        return true;
    }

    std::vector<GameObject*> Scene::getObjects() const {
        return this->_objects;
    }

    unsigned int Scene::getHighestZ() const {
        return this->_highestZ;
    }

    std::unordered_map<unsigned int, std::vector<GameObject*>> Scene::getObjectMap() const {
        return this->_objectMap;
    };

}