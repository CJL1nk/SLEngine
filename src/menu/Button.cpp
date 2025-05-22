//
// Created by CJ on 5/20/2025.
//

#include "Button.h"

namespace UI {

    template <typename Func, typename... Args>
    void Button::setPress(Func&& f, Args&&... args) {
        // Store a lambda that captures the function and its arguments
        this->_function = std::bind(std::forward<Func>(f), std::forward<Args>(args)...);
    }

    void Button::press() {
        if (this->_function) { // If they've added a function, call it
            this->_function();
        }
    }

}