//
// Created by realj on 12/6/2021.
//

#include "menubar.h"

menubar::menubar(sf::RectangleShape GUI_COLOR, float LISTBOX_LENGTH) {
    font.loadFromFile("fonts/arial.ttf");
    menubarBackground.setSize(sf::Vector2f(LISTBOX_LENGTH, 15.0f));
    menubarBackground.move(0,0);
    menubarBackground.setFillColor(sf::Color(sf::Color::White));


    menubarDropdown.setSize(sf::Vector2f(15, menubarBackground.getSize().y));
}

void menubar::updatemenubar(sf::RectangleShape GUI_BACKGROUND, int slot, sf::RenderWindow &window, int size,
                            std::string *items, int &selectedItem) {
    menubarDropdown.setPosition(menubarBackground.getGlobalBounds().left + menubarBackground.getSize().x - menubarDropdown.getSize().x, menubarBackground.getPosition().y);
    if (init) {
        for (int i = 0; i <= size; i++) {

            dropDowns[i].setSize(menubarBackground.getSize());
            dropDowns[i].setFillColor(sf::Color(themeColor.r - 60.0f, themeColor.g - 60.0f, themeColor.b - 60.0f));
            dropDownsText[i].setCharacterSize(12);
            dropDownsText[i].setFillColor(sf::Color(sf::Color::White));
            dropDownsText[i].setFont(font);
            dropDownsText[i].setString(items[i]);
            selectedText.setCharacterSize(13);
            selectedText.setFillColor(sf::Color(sf::Color::Black));
            selectedText.setFont(font);
            selectedText.setString(actual_selectedItem);
        }
    }

    selectedText.setPosition(menubarBackground.getPosition().x + 5.0f, menubarBackground.getPosition().y - 2.0f);
    selectedText.setString(actual_selectedItem);
    for (int i = 0; i <= size; i++) {
        if (i == 0) {
            dropDowns[0].setPosition(menubarBackground.getPosition().x, menubarBackground.getPosition().y + 15);
        }
        dropDowns[i].setPosition(menubarBackground.getPosition().x, menubarBackground.getPosition().y + i * 15 + 15);
        dropDownsText[i].setPosition(dropDowns[i].getPosition().x + 10.0f, dropDowns[i].getPosition().y - 1.0f);

        if (checkHover(window, dropDowns[i])) {
            dropDowns[i].setFillColor(sf::Color(sf::Color::Black));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                actual_selectedItem = items[i];
                selectedItem = i + 1;
                dropDownActivated = false;
            }
        } else {
            dropDowns[i].setFillColor(sf::Color(sf::Color::Blue));
        }

    }


    if (checkHover(window, menubarDropdown)) {
        menubarDropdown.setFillColor(sf::Color(sf::Color::Blue));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && dropDownClock.getElapsedTime().asSeconds() >= 0.2f) {

            dropDownClock.restart();
            dropDownClock2.restart();
            dropDownActivated = !dropDownActivated;
        }
    }

    else {
        menubarDropdown.setFillColor(sf::Color(sf::Color::Black));
    }

}

void menubar::Draw(sf::RenderWindow &window, sf::RectangleShape GUI_PID, int slot, int size, std::string *items,
                   int &selectedItem) {
    window.draw(menubarBackground);
    window.draw(menubarDropdown);

    if (dropDownActivated) {
        for (int i = 0; i <= size; i++) {
            window.draw(dropDowns[i]);
            window.draw(dropDownsText[i]);
        }
    }
    window.draw(selectedText);
    updatemenubar(GUI_PID, slot, window, size, items, selectedItem);

}

bool menubar::checkHover(sf::RenderWindow &window, sf::RectangleShape Object) {
    if (sf::Mouse::getPosition(window).x >= Object.getPosition().x &&
        sf::Mouse::getPosition(window).x <= Object.getPosition().x + Object.getSize().x &&
        sf::Mouse::getPosition(window).y >= Object.getPosition().y &&
        sf::Mouse::getPosition(window).y <= Object.getPosition().y + Object.getSize().y)
        return true;
    else
        return false;
}

bool menubar::checkHoverOppo(sf::RenderWindow &window, sf::RectangleShape Object) {
    if (sf::Mouse::getPosition(window).x > Object.getPosition().x + Object.getSize().x ||
        sf::Mouse::getPosition(window).x < Object.getPosition().x ||
        sf::Mouse::getPosition(window).y > Object.getPosition().y + Object.getSize().y ||
        sf::Mouse::getPosition(window).y < Object.getPosition().y
            )
        return true;
    else
        return false;
}
