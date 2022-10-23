//
// Created by realj on 12/6/2021.
//

#ifndef SFML_PROJECT_LOGO_H
#define SFML_PROJECT_LOGO_H
#include <sstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextInput.h"

class Logo {
public:


    Logo();
    Logo(int size, sf::Color color, bool sel);

    void setFont(sf::Font &font);
    void setPosition(sf::Vector2f pos);

    void drawTo(sf::RenderWindow &window);

    sf::Text logo;
    sf::String textbox;


};


#endif //SFML_PROJECT_LOGO_H
