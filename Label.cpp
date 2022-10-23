//
// Created by realj on 11/28/2021.
//

#include "Label.h"

Label::Label() {

}

void Label::setPosition(float x, float y) {
label.setPosition(x,y);
}

sf::FloatRect Label::getGlobalBounds() {
    return label.getGlobalBounds();
}

void Label::draw(sf::RenderTarget &window, sf::RenderStates states) const {
window.draw(label);
}

void Label::setString(const std::string &string) {
label.setString(string);
}
