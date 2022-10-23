//
// Created by realj on 11/28/2021.
//

#ifndef SFML_PROJECT_MYOBJECT_H
#define SFML_PROJECT_MYOBJECT_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include "MouseEvents.h"
#include "Label.h"
#include "Slider2.h"


class MyObject : public sf::Drawable {
private:
    sf::RectangleShape rectangleShape;
    sf::RectangleShape overRectangleShape;

    sf::RectangleShape botrectangleShape;
    sf::RectangleShape overbotrectangleShape;


    States states;

public:
    MyObject();
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);

};


#endif //SFML_PROJECT_MYOBJECT_H
