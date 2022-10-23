//
// Created by realj on 11/28/2021.
//

#include "MyObject.h"

MyObject::MyObject() {
    rectangleShape.setSize({370, 75});
    rectangleShape.setPosition({420, 100});
    rectangleShape.setFillColor(sf::Color::White);

    overRectangleShape.setSize({350, 65});
    overRectangleShape.setFillColor(sf::Color::Black);
    overRectangleShape.setPosition({430, 105});




    botrectangleShape.setSize({1280,350});
    botrectangleShape.setPosition({0,400});
    botrectangleShape.setFillColor(sf::Color::White);

    overbotrectangleShape.setSize({1280,350});
    overbotrectangleShape.setPosition({0,410});
    overbotrectangleShape.setFillColor(sf::Color::Black);

}

void MyObject::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    MouseEvents::toggleState(sf::Mouse::Left, TextEntered, states);
    MouseEvents::toggleState(sf::Mouse::Right, MAKE_BLUE, states);

}

void MyObject::update() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {

        overbotrectangleShape.setFillColor(sf::Color(sf::Color::Blue));


    }
}

void MyObject::draw(sf::RenderTarget &window, sf::RenderStates states) const {

        window.draw(rectangleShape);
        window.draw(overRectangleShape);
        window.draw(botrectangleShape);
        window.draw(overbotrectangleShape);

}

void MyObject::setPosition(float x, float y) {

}
