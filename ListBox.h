//
// Created by realj on 11/24/2021.
//

#ifndef SFML_PROJECT_LISTBOX_H
#define SFML_PROJECT_LISTBOX_H
#include <SFML/Graphics.hpp>

class ListBox {
public:
    ListBox(sf::RectangleShape GUI_COLOR, float LISTBOX_LENGTH);
    void updateListBox(sf::RectangleShape GUI_BACKGROUND, int slot, sf::RenderWindow &window, int size, std::string items[], int &selectedItem);

    void Draw(sf::RenderWindow &window, sf::RectangleShape GUI_PID, int slot, int size, std::string items[], int &selectedItem);
    bool checkHover(sf::RenderWindow &window, sf::RectangleShape Object);
    bool checkHoverOppo(sf::RenderWindow& window, sf::RectangleShape Object);

private:
    sf::RectangleShape listBoxBackground;
    sf::Vector2f LISTBOX_POSITION;

    sf::RectangleShape listBoxDropdown;

    sf::RectangleShape dropDowns[99];
    sf::Text dropDownsText[99];
    sf::Font font;

    sf::Text selectedText;

    sf::Clock dropDownClock;
    sf::Clock dropDownClock2;

    std::string actual_selectedItem;

    sf::RectangleShape listBoxDropdownTexture;

    bool init = true;

    bool dropDownActivated = false;

    sf::Color themeColor;

    sf::Texture dropdownTex;
};


#endif //SFML_PROJECT_LISTBOX_H
