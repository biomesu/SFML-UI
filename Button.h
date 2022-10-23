//
// Created by realj on 11/24/2021.
//

#ifndef SFML_PROJECT_BUTTON_H
#define SFML_PROJECT_BUTTON_H
#include <SFML/Graphics.hpp>

class Button {
public:

    Button(sf::RectangleShape GUI_PID, sf::RectangleShape GUI_COLOR, sf::Color TEXT_COLOR, std::string BUTTON_TEXT);
    void updateButton(sf::RectangleShape GUI_PID, int slot, sf::RenderWindow &window);

    bool isButtonClicked(sf::RenderWindow &window);

    void Draw(sf::RenderWindow &window, sf::RectangleShape GUI_PID, sf::RectangleShape GUI_COLOR, int slot);

private:
    sf::RectangleShape button;


    bool isClicked = false;
    sf::Vector2f BUTTON_POSITION;
    sf::Vector2f BUTTON_TEXTPOSITION;

    sf::Color themeColor;
    sf::Vector2f buttonSize;
    sf::Clock buttonClock;
    sf::Clock buttonClockAnim;
    sf::Text buttonText;
    sf::Text rightText;
    sf::Font buttonFont;
};


#endif //SFML_PROJECT_BUTTON_H
