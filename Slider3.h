//
// Created by realj on 11/24/2021.
//

#ifndef SFML_PROJECT_SLIDER3_H
#define SFML_PROJECT_SLIDER3_H
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

class Slider3 {
public:

    // INT SLIDER 2

    Slider3(sf::RectangleShape GUI_COLOR, sf::Color TEXT_COLOR, float SliderLength, std::string TEXT);

    void updateSlider(sf::RectangleShape GUI_BACKGROUND, int slot, sf::RenderWindow& window);

    void changeValue(int& value, int min, int max, int& value2, int v2_min, int v2_max, int& value3, int v3_min, int v3_max);

    void Draw(sf::RenderWindow& window, int slot, sf::RectangleShape GUI_PID, int& v1, int v1_min, int v1_max,
              int& v2, int v2_min, int v2_max, int& v3, int v3_min, int v3_max);

private:
    sf::RectangleShape SliderBackground;
    sf::RectangleShape SliderBackground2;
    sf::RectangleShape SliderBackground3;

    sf::RectangleShape slider;
    sf::RectangleShape slider2;
    sf::RectangleShape slider3;

    sf::Vector2f newSliderPos;
    sf::Vector2f newSliderPos2;
    sf::Vector2f newSliderPos3;
    sf::Vector2f sliderPos;



    sf::FloatRect shownValueRect;
    sf::Text shownValueText;

    sf::FloatRect shownValueRect2;
    sf::Text shownValueText2;

    sf::FloatRect shownValueRect3;
    sf::Text shownValueText3;


    sf::RectangleShape sliderOverHang;
    sf::RectangleShape sliderOverHang2;
    sf::RectangleShape sliderOverHang3;

    sf::Text text;
    sf::Font font;

    float x;
    float x1;
    float x2;
    int y;

    bool flag = true;
    bool negative = false;
    bool positive = false;

    bool SliderInitflag = true;

    sf::Color themeColor;
};


#endif //SFML_PROJECT_SLIDER3_H
