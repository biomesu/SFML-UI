//
// Created by realj on 12/6/2021.
//

#ifndef SFML_PROJECT_MENUBAR_H
#define SFML_PROJECT_MENUBAR_H
#include <SFML/Graphics.hpp>

class menubar {
public:
    menubar(sf::RectangleShape GUI_COLOR, float LISTBOX_LENGTH);
    void updatemenubar(sf::RectangleShape GUI_BACKGROUND, int slot, sf::RenderWindow &window, int size, std::string items[], int &selectedItem);
    void Draw(sf::RenderWindow &window,sf::RectangleShape GUI_PID, int slot, int size, std::string items[], int &selectedItem);
    bool checkHover(sf::RenderWindow &window, sf::RectangleShape Object);
    bool checkHoverOppo(sf::RenderWindow& window, sf::RectangleShape Object);

private:
    sf::RectangleShape menubarBackground;
    //positioning of the drop down box
    sf::Vector2f menubar_POSITION;

    //shape for the dropdown list
    sf::RectangleShape menubarDropdown;

    //amount of shapes/text for the dropdown list and font being used for that dropdownlist
    sf::RectangleShape dropDowns[99];
    sf::Text dropDownsText[99];
    sf::Font font;

    //selected text for the drop down
    sf::Text selectedText;

    //clock for the dropdown list so while the menu is open it lasts longer
    sf::Clock dropDownClock;
    sf::Clock dropDownClock2;

    std::string actual_selectedItem;


    bool init = true;

    bool dropDownActivated = false;

    //for the dropdown background color
    sf::Color themeColor;

};


#endif //SFML_PROJECT_MENUBAR_H
