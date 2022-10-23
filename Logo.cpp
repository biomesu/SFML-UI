//
// Created by realj on 12/6/2021.
//

#include "Logo.h"

Logo::Logo() {

}

Logo::Logo(int size, sf::Color color, bool sel) {

}

void Logo::setFont(sf::Font &font) {
    font.loadFromFile("Fonts/arial.ttf");
    logo.setFont(font);
}

void Logo::setPosition(sf::Vector2f pos) {

}

void Logo::drawTo(sf::RenderWindow &window) {
   // window.draw(logo);

}
