//
// Created by realj on 11/24/2021.
//

#ifndef SFML_PROJECT_GUI_H
#define SFML_PROJECT_GUI_H
#include <SFML/Graphics.hpp>


class gui {
public:

    gui(std::string WINDOW_TITLE, sf::Vector2f GUI_SIZE, sf::Vector2f GUI_POSITION, sf::Color GUI_BACKGROUND_COLOR,
        sf::Color TOP_BAR_COLOR, sf::Color TEXT_COLOR);
    sf::RectangleShape getGUI();
    sf::RectangleShape getGUIColor();

    void DRAW_GUI(sf::RenderWindow& window);
    void UPDATE_GUI(sf::RenderWindow& window);

private:

    sf::RectangleShape GUI_BACKGROUND;
    sf::RectangleShape TOP_BAR;
    sf::Text WINDOW_TEXT;
    sf::Font font;
    int ELEMENT_COUNT = 0;
    bool flag = true;
    //bool slots[5] = {false, false, false, false, false};

    struct GUI_IDS {
        sf::RectangleShape GUI_PID;
        sf::RectangleShape TOP_BAR;
    };
};


#endif //SFML_PROJECT_GUI_H
