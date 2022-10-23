//
// Created by realj on 11/28/2021.
//

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H
#include <map>
#include "ObjectStates.h"

class States {
private:
    std::map<ObjectStates, bool> states;

public:
    States();
    bool checkState(ObjectStates state) const;
    void disableState(ObjectStates state);
    void enableState(ObjectStates state);
};


#endif //SFML_PROJECT_STATES_H
