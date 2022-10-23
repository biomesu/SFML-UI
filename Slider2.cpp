//
// Created by realj on 11/24/2021.
//

#include "Slider2.h"


Slider2::Slider2(sf::RectangleShape GUI_COLOR, sf::Color TEXT_COLOR, float SliderLength, std::string TEXT) {


    SliderBackground.setSize(sf::Vector2f(200, 15.0f));
    themeColor = sf::Color(GUI_COLOR.getFillColor().r - 40.0f, GUI_COLOR.getFillColor().g - 40.0f, GUI_COLOR.getFillColor().b - 40.0f);
    SliderBackground.setFillColor(sf::Color(GUI_COLOR.getFillColor().r - 40.0f, GUI_COLOR.getFillColor().g - 40.0f, GUI_COLOR.getFillColor().b - 40.0f));
    slider.setSize(sf::Vector2f(10, 15.0f));
    slider.setFillColor(sf::Color(themeColor.r + 40, themeColor.g + 40, themeColor.b + 40));


    sliderOverHang.setSize(sf::Vector2f(SliderBackground.getSize().x + slider.getPosition().x, 13.0f));
    sliderOverHang.setPosition(SliderBackground.getPosition().x, SliderBackground.getPosition().y);
    sliderOverHang.setFillColor(sf::Color::Black);

    font.loadFromFile("Fonts/arial.ttf");
    text.setFont(font);
    text.setPosition(290,207);
    text.setCharacterSize(13);
    text.setString(TEXT);


}

void Slider2::updateSlider(sf::RectangleShape GUI_BACKGROUND, int slot, sf::RenderWindow &window) {
    sf::Vector2f SLIDER_POSITION;
    sf::Vector2f SLIDER_POSITION2;

    SLIDER_POSITION = sf::Vector2f(GUI_BACKGROUND.getGlobalBounds().left + 10.0f, GUI_BACKGROUND.getGlobalBounds().top + slot * 20.0f);
    SliderBackground.setPosition(SLIDER_POSITION);

    sliderOverHang.setSize(sf::Vector2f(slider.getPosition().x - SliderBackground.getPosition().x, 11.0f));
    sliderOverHang.setPosition(SliderBackground.getPosition().x + 3.0f, SliderBackground.getPosition().y + 2);


    if (SliderInitflag) {
        SLIDER_POSITION2 = sf::Vector2f(SliderBackground.getGlobalBounds().left + SliderBackground.getSize().x / 2 - 5.0f, SliderBackground.getGlobalBounds().top - 3.0f);
        slider.setPosition(SLIDER_POSITION2);
        SliderInitflag = false;
    }

    if (sf::Mouse::getPosition(window).x >= slider.getPosition().x &&
        sf::Mouse::getPosition(window).x <= slider.getPosition().x + slider.getSize().x &&
        sf::Mouse::getPosition(window).y >= slider.getPosition().y &&
        sf::Mouse::getPosition(window).y <= slider.getPosition().y + slider.getSize().y)
    {
        slider.setFillColor(sf::Color(themeColor.r + 50, themeColor.g + 50, themeColor.b + 50));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            slider.setPosition(sf::Mouse::getPosition(window).x - slider.getSize().x / 2, SliderBackground.getPosition().y);
            newSliderPos.x = slider.getPosition().x - SliderBackground.getPosition().x;
           // text.setFillColor(sf::Color::Red);

        }

    }
    else {
        slider.setFillColor(sf::Color(themeColor.r + 30, themeColor.g + 30, themeColor.b + 30));
        slider.setPosition(newSliderPos.x + SliderBackground.getSize().x + SliderBackground.getGlobalBounds().left - SliderBackground.getSize().x, SliderBackground.getPosition().y);
    }

    if (sf::Mouse::getPosition(window).x >= SliderBackground.getPosition().x &&
        sf::Mouse::getPosition(window).x <= SliderBackground.getPosition().x + SliderBackground.getSize().x &&
        sf::Mouse::getPosition(window).y >= SliderBackground.getPosition().y &&
        sf::Mouse::getPosition(window).y <= SliderBackground.getPosition().y + SliderBackground.getSize().y)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            slider.setPosition(sf::Mouse::getPosition(window).x - slider.getSize().x / 2, slider.getPosition().y);

        }
    }

    if (slider.getPosition().x >= SliderBackground.getPosition().x + SliderBackground.getSize().x)
    {
        slider.setPosition(SliderBackground.getPosition().x + SliderBackground.getSize().x, slider.getPosition().y);
    }
    if (slider.getPosition().x <= SliderBackground.getPosition().x)
    {
        slider.setPosition(SliderBackground.getPosition().x, slider.getPosition().y);
    }

}


void Slider2::Draw(sf::RenderWindow &window, int slot, sf::RectangleShape GUI_PID, float &value, float min, float max) {
    window.draw(SliderBackground);
    window.draw(sliderOverHang);
    window.draw(slider);
    window.draw(text);
    updateSlider(GUI_PID, slot, window);

}



