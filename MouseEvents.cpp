//
// Created by realj on 11/28/2021.
//

#include "MouseEvents.h"

void MouseEvents::toggleState(sf::Mouse::Button button, ObjectStates state, States &states) {
    if (sf::Mouse::isButtonPressed(button)) {
        if (!states.checkState(state))
            states.enableState(state);
        else
            states.disableState(state);
    }
}
