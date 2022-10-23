//
// Created by realj on 11/24/2021.
//

#ifndef SFML_PROJECT_TEXT_H
#define SFML_PROJECT_TEXT_H
#include <SFML/Graphics.hpp>

class text {
public:

    text(sf::RectangleShape GUI_BACKGROUND, std::string TEXT, std::string TEXT2, std::string TEXT3, std::string LOGOTEXT, std::string PICKERTEXT, sf::Color TEXT_COLOR, sf::RenderWindow& window);
    void updateText(sf::RenderWindow &window, int slot, sf::RectangleShape GUI_BACKGROUND);

    void Draw(sf::RenderWindow& window, int slot, sf::RectangleShape GUI_PID);


    sf::Text returnText();

    sf::Text returnText2();

    sf::Text returnText3();

    // logo text
    sf::Text returnText4();

    sf::Text returnText5();

private:

    //first text
    sf::Text Text;
    sf::Font font;
    sf::Vector2f TEXT_POSITION;

    //second text
    sf::Text Text2;
    sf::Font font2;

    sf::Vector2f TEXT2_POSITION;

    //third text
    sf::Text Text3;
    sf::Font font3;

    sf::Vector2f TEXT3_POSITION;

    //Logo text
    sf::Text LogoText;
    sf::Font Logofont;

    sf::Vector2f LOGOTEXT_POSITION;

    //Color Picker Text
    sf::Text PickerText;
    sf::Font Pickerfont;

    sf::Vector2f PICKER_POSITION;

    bool flag = true;
};


#endif //SFML_PROJECT_TEXT_H
