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
        return true;
    }

    std::vector<GameObject*> Scene::getObjects() {
        return this->_objects;
    }

}