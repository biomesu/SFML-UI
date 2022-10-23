//
// Created by realj on 11/24/2021.
//

#ifndef SFML_PROJECT_CHECKBOX_H
#define SFML_PROJECT_CHECKBOX_H
#include <SFML/Graphics.hpp>

class CheckBox {
public:

    CheckBox(sf::RectangleShape GUI_COLOR, std::string CHECKBOX_TEXT, sf::Color TEXT_COLOR);\
    void Draw(sf::RenderWindow& window, int slot, sf::RectangleShape GUI_PID, bool &BOOLEAN);

    void updateCheckBox(int slot, sf::RectangleShape GUI_BACKGROUND, sf::RenderWindow &window);

private:
    sf::RectangleShape checkBox_Background;
    sf::Vector2f CHECKBOX_POSITION;


    sf::RectangleShape checkBox_Check;
    sf::Texture check_Texture;
    sf::Clock checkBoxTimer;

    bool activateFlag = false;

    bool boolean2;

    sf::Text checkBoxText;
    sf::Font checkBoxFont;

    sf::Color themeColor;

    bool activated = false;

};


#endif //SFML_PROJECT_CHECKBOX_H
