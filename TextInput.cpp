//
// Created by realj on 11/28/2021.
//



#include "TextInput.h"

TextInput::TextInput() {

}

TextInput::TextInput(int size, sf::Color color, bool sel) {
    textbox.setCharacterSize(size);
    textbox.setFillColor(color);
    isSelected = sel;




    if (isSelected)
        textbox.setString("_");
    else
        textbox.setString("+");
}

void TextInput::setFont(sf::Font &fonts) {
    textbox.setFont(fonts);
}

void TextInput::setPosition(sf::Vector2f point) {
    textbox.setPosition(point);
}

void TextInput::setLimit(bool ToF) {
    hasLimit = ToF;

}

void TextInput::setLimit(bool ToF, int lim) {
    hasLimit = ToF;
    limit = lim - 1;

}

void TextInput::setSelected(bool sel) {
    isSelected = sel;

    if (!sel) {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); i++) {
            newT += t[i];
        }

        textbox.setString(newT);
    }

}

std::string TextInput::getText() {
    return text.str();
}

void TextInput::drawTo(sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        textbox.setPosition(sf::Mouse::getPosition(window).x - textbox.getCharacterSize() / 2, textbox.getPosition().y);


    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

      //  textbox.setFillColor(sf::Color(255,255,255,128));


    }

    window.draw(textbox);


}

void TextInput::typedOn(sf::Event input) {
    if (isSelected) {
        int charTyped = input.text.unicode;

        // Only allow normal inputs:
        if (charTyped < 128) {
            if (hasLimit) {
                // If there's a limit, don't go over it:
                if (text.str().length() <= limit) {
                    inputLogic(charTyped);
                }
                    // But allow for char deletions:
                else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                  //  deleteLastChar();
                }
            }
                // If no limit exists, just run the function:
            else {
                inputLogic(charTyped);
            }
        }
    }
}

void TextInput::changeColor() {

  //  textbox.setFillColor(sf::Color::Red);

}






