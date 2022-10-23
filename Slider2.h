//
// Created by realj on 11/24/2021.
//

#ifndef SFML_PROJECT_SLIDER2_H
#define SFML_PROJECT_SLIDER2_H
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include "TextInput.h"


#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Slider2 {
public:

    //FLOAT SLIDER

    Slider2(sf::RectangleShape GUI_COLOR, sf::Color TEXT_COLOR, float SliderLength, std::string TEXT);

    void updateSlider(sf::RectangleShape GUI_BACKGROUND, int slot, sf::RenderWindow& window);

    void Draw(sf::RenderWindow& window, int slot, sf::RectangleShape GUI_PID, float& value, float min, float max);

    sf::Text text;
    sf::Font font;

private:
    sf::RectangleShape SliderBackground;

    sf::RectangleShape slider;

    sf::Vector2f newSliderPos;
    sf::Vector2f sliderPos;


    sf::RectangleShape sliderOverHang;

    float x;
    int y;

    bool flag = true;
    bool negative = false;
    bool positive = false;

    bool SliderInitflag = true;

    sf::Color themeColor;

};



#endif //SFML_PROJECT_SLIDER2_H
