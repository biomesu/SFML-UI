//
// Created by realj on 11/28/2021.
//

#ifndef SFML_PROJECT_MOUSEEVENTS_H
#define SFML_PROJECT_MOUSEEVENTS_H
#include "ObjectStates.h"
#include "States.h"
#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    static void toggleState(sf::Mouse::Button button,ObjectStates state,States& states);

};


#endif //SFML_PROJECT_MOUSEEVENTS_H
