//
// Created by realj on 11/24/2021.
//

#include "gui.h"

gui::gui(std::string WINDOW_TITLE, sf::Vector2f GUI_SIZE, sf::Vector2f GUI_POSITION, sf::Color GUI_BACKGROUND_COLOR,
         sf::Color TOP_BAR_COLOR, sf::Color TEXT_COLOR) {
    GUI_BACKGROUND.setSize(GUI_SIZE);
    GUI_BACKGROUND.setFillColor(GUI_BACKGROUND_COLOR);
    GUI_BACKGROUND.setPosition(GUI_POSITION);
    GUI_BACKGROUND.setOrigin(GUI_BACKGROUND.getSize() / 2.0f);
    TOP_BAR.setPosition(sf::Vector2f(GUI_BACKGROUND.getGlobalBounds().left, GUI_BACKGROUND.getGlobalBounds().top));
    TOP_BAR.setOrigin(TOP_BAR.getSize() / 2.0f);
    TOP_BAR.setFillColor(sf::Color::White);
    TOP_BAR.setSize(sf::Vector2f(GUI_BACKGROUND.getSize().x, 20.0f));


}

sf::RectangleShape gui::getGUI() {
    return GUI_BACKGROUND;
}

sf::RectangleShape gui::getGUIColor() {
    return TOP_BAR;
}

void gui::DRAW_GUI(sf::RenderWindow &window) {
    window.draw(GUI_BACKGROUND);
    window.draw(WINDOW_TEXT);
    window.draw(TOP_BAR);
}

void gui::UPDATE_GUI(sf::RenderWindow &window) {
    if (sf::Mouse::getPosition(window).x >= TOP_BAR.getPosition().x &&
        sf::Mouse::getPosition(window).x <= TOP_BAR.getPosition().x + TOP_BAR.getSize().x &&
        sf::Mouse::getPosition(window).y >= TOP_BAR.getPosition().y &&
        sf::Mouse::getPosition(window).y <= TOP_BAR.getPosition().y + TOP_BAR.getSize().y)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {

        }
    }
}
